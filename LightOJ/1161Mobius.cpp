#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10004

using namespace std;

vector<ll> D[maxn];
ll M[maxn];

void preCal()
{
      for (int i=1 ; i<maxn ; i++){
            for (int j=i ; j<maxn ; j+=i){
                  D[j].push_back(i);
            }
      }
}

void mobius()
{
      M[1] = 1;
      for (int i=1 ; i<maxn ; i++){
            for (int j=i+i ; j<maxn ; j+=i)M[j] -= M[i];
      }
}

int main()
{
      mobius();
      preCal();
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){

            ll n;
            scanf("%lld",&n);

            ll f[maxn];
            memset(f,0,sizeof f);

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  for (int j=0 ; j<D[a].size() ; j++){
                        f[D[a][j]]++;
                  }
            }
            for (int i=1 ; i<maxn ; i++)f[i] = (f[i]*(f[i]-1)*(f[i]-2)*(f[i]-3))/24;

            /** Exclusion DP O(nlog(n))
                  for (int i=maxn-1 ; i>0 ; i--){
                        for (int j=i+i ; j<maxn ; j+=i)f[i] -= f[j];
                  }
                  printf("Case %d: %lld\n",_t,f[1]);
            **/


            ///Mobius O(n)
            ll ans = 0;
            for (int i=1 ; i<maxn ; i++)ans += M[i]*f[i];
            printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}
