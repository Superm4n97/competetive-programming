#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define maxn 200005

using namespace std;

ll C[maxn] , vis[maxn] , ans , mn[maxn];
vector<ll> G[maxn];

int main()
{
      for (int i=0 ; i<maxn ; i++){
            mn[i] = 100000000000000017;
      }
      ans = -100000000000000017;

      ll n , m;
      scl(n),scl(m);

      for (int i=1 ; i<=n ; i++)scl(C[i]);

      for (int i=1;  i<=m ; i++){
            ll a, b;
            scl(a),scl(b);
            G[a].push_back(b);
      }

      for (int u=1 ; u<=n ; u++){
            ans = max(ans,C[u]-mn[u]);
            mn[u] = min(mn[u],C[u]);
            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];
                  mn[v] = min(mn[v],mn[u]);
            }
      }

      printf("%lld\n",ans);

      return 0;
}
