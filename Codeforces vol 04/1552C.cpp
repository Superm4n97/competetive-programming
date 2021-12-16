#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%I64d",&w)
#define show(x)         cout << #x << " : " << x << endl
#define maxn 400

using namespace std;

vector<pair<ll,ll> >vp;
ll n, k, A[maxn];

void clean()
{
      memset(A,0,sizeof A);
      vp.clear();
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n) , scl(k);
            clean();
            for (int i=1 ; i<=k ; i++){
                  ll a, b;
                  scl(a),scl(b);
                  if (a>b)swap(a,b);
                  A[a] = b;
                  A[b] = a;
                  vp.push_back({a,b});
            }
            vector<ll> v;
            for (int i=1 ; i<=2*n ; i++){
                  if (A[i]==0){
                        v.push_back(i);
                  }
            }

            ll sz = v.size()/2;

            for (int i=0 ; i<sz ; i++){
                  A[v[i]] = v[sz+i];
                  A[v[sz+i]] = v[i];
                  vp.push_back({v[i],v[sz+i]});
            }

            sort(vp.begin(),vp.end());

            ll ans = 0;

            for (int i=1 ; i<vp.size(); i++){
                  for (int j=i-1 ; j>=0 ; j--){
                        if (vp[i].second>vp[j].second && vp[i].first<vp[j].second){
                              ans++;
//                              cout << vp[i].first << "," << vp[i].second<< " : ";
//                              cout << vp[j].first << "," << vp[j].second << endl;
                        }
                  }
            }
            printf("%lld\n",ans);
      }

      return 0;
}

/**

*/
