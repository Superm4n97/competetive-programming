#include<bits/stdc++.h>
#define ll long long int
#define maxn 300005

using namespace std;

ll n,m , sz[maxn] , dp[maxn];
vector<ll> G[maxn];

ll rec(ll u)
{
      if (dp[u]!=-1)return dp[u];
      ll ret = 1;
      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (sz[v]>sz[u]){
                  ret = max(rec(v)+1,ret);
            }
      }
      return dp[u] = ret;
}

int main()
{
      memset(dp,-1,sizeof dp);

      scanf("%lld %lld",&n,&m);
      for (int i=0 ; i<m ; i++){
            ll a, b;
            scanf("%lld %lld",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
      }

      for (int i=0 ; i<n ; i++)sz[i] = G[i].size();
      ll ans = 0;
      for (int i=0; i<n ; i++){
            ans = max(ans,rec(i));
      }
      printf("%lld\n",ans);

      return 0;
}
