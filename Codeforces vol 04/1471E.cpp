#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005
#define scl(x) scanf("%I64d",&x)

using namespace std;

ll n ,m, vis[maxn] , mark[maxn];
vector<ll> G[maxn];

void clean()
{
      for (int i=0 ; i<n+3 ; i++){
            G[i].clear();
            vis[i] = mark[i] = 0;
      }
}

ll connects(ll u)
{
      ll cnt = 1;
      vis[u] = 1;
      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (vis[v]==0){
                  cnt+=connects(v);
            }
      }
      return cnt;
}

void sol()
{
      for (int i=0 ; i<n+4 ; i++)vis[i] = 0;
      mark[1] = 1;
      queue<ll> q;
      q.push(1);

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            if (mark[u]&1){
                  for (int i=0 ; i<G[u].size() ; i++){
                        ll v = G[u][i];
                        if (vis[v]==0){
                              mark[v] = mark[u]+1;
                              q.push(v);
                              vis[v] = 1;
                        }
                        else {
                              if (mark[v]&1)mark[v]++;
                        }
                  }
            }
            else {
                  for (int i=0 ; i<G[u].size() ; i++){
                        ll v = G[u][i];
                        if (vis[v]==0){
                              q.push(v);
                              vis[v] = 1;
                              mark[v] = mark[u]+1;
                        }
                  }
            }
      }
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n) , scl(m);
            clean();
            for (int i=1 ; i<=m ; i++){
                  ll a, b;
                  scl(a),scl(b);
                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            if (connects(1)!=n){
                  printf("NO\n");
            }
            else {
                  printf("YES\n");
                  sol();
                  vector<ll> ans;
                  for (int i=1 ; i<=n ; i++){
                        if (mark[i]&1)ans.push_back(i);
                  }
                  printf("%d\n",ans.size());
                  for (int i=0 ; i<ans.size() ; i++)printf("%I64d ",ans[i]);
                  printf("\n");
            }
      }

      return 0;
}
