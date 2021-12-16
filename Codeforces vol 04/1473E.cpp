#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 200005
#define inf 10000000000000016

using namespace std;

ll n,m,ans[maxn] , mx[maxn] , mn[maxn] , d[maxn];
vector<ll> G[maxn] , W[maxn];

void bfs()
{
      priority_queue<pair<ll,ll> > pq;

      d[1] = 0;
      ans[1] = 0;

      for (int i=2 ; i<=n ; i++)d[i] = inf;

      for (int i=0  ; i<G[1].size() ; i++){
            ll v = G[1][i];
            ll c = W[1][i];
            mx[v] = d[v] = mn[v] = c;
            pq.push({-c,v});
      }

      while(!pq.empty()){
            ll u = pq.top().second;
            pq.pop();

            if (ans[u]!=-1)continue;

            ans[u] = d[u];

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];
                  if (ans[v]!=-1)continue;

                  ll w = W[u][i];
                  ll x = max(mx[u],w) , y = min(mn[u],w);
                  ll cost = d[u]+mx[u]-mn[u] + w-x+y;

                  if (cost<d[v]){
                        d[v] = cost;
                        mx[v] = x , mn[v] = y;
                        pq.push({-d[v],v});
                  }
            }
      }
}

int main()
{
      scl(n),scl(m);

      for (int i=0 ; i<m ; i++){
            ll a, b , c;
            scl(a) , scl(b) , scl(c);

            G[a].push_back(b);
            G[b].push_back(a);

            W[a].push_back(c);
            W[b].push_back(c);
      }

      memset(ans,-1,sizeof ans);

      bfs();

      for (int i=2 ; i<=n ; i++)printf("%I64d ",d[i]);
      printf("\n");

      return 0;
}
