#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x " : " << x << endl
#define maxn 200005

using namespace std;

ll n,m , A[maxn] , csum[maxn];

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n >> m;

            vector<pair<ll,ll>>v;
            ll mx = 0;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  csum[i] = csum[i-1]+A[i];
                  if (csum[i]>mx){
                        v.push_back({csum[i],i});
                        mx = csum[i];
                  }
            }
            ll v_size = v.size();
            ll total = csum[n];

            while(m--){
                  ll x,sch , pre = 0;
                  cin >> x;

                  if (total<=0 && x>mx)cout << "-1 ";
                  else {
                        ll need = max(0LL,x-mx);
                        ll temp = 0;

                        if (total>0){
                              ll temp = (need+total-1)/total;
                              pre = temp*n;
                              x -= (temp*total);
                        }

                        ll b = 0 , e = v_size-1 , ret = v_size;
                        while(b <= e){
                              ll mid = (b+e)/2;
                              if(v[mid].first>=x){
                                    ret = min(ret,mid);
                                    e = mid-1;
                              }
                              else b = mid+1;
                        }

                        pre+=v[ret].second;
                        cout << pre-1<< " ";
                  }
            }
            cout << "\n";
      }

      return 0;
}
