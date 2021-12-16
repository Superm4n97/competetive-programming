#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10005

using namespace std;

vector<ll> D[maxn];

void initialize()
{
      for (int i=1; i<maxn ; i++){
            for (int j = i ; j<maxn ; j+=i){
                  D[j].push_back(i);
            }
      }
}

ll nc4(ll n)
{
      return n*(n-1)*(n-2)*(n-3)/24;
}

int main()
{
      initialize();

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc; _t++){
            ll n, f[maxn] , g[maxn];
            scanf("%lld",&n);

            memset(f,0,sizeof f);
            memset(g,0,sizeof g);

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);

                  for (int j=0 ; j<D[a].size() ; j++){
                        f[D[a][j]]++;
                  }
            }
            //show(n);
            for (int i = maxn - 2 ; i>=1 ; i--){
                  f[i] = nc4(f[i]);
                  g[i] = f[i];

                  for (int j = i+i ; j<maxn ; j+=i)g[i]-=g[j];
            }

            printf("Case %d: %lld\n",_t,g[1]);

      }

      return 0;
}
