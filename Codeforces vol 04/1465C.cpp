#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 400005

using namespace std;

ll n ,m , vis[maxn];
vector<ll> G[maxn];

void clean()
{
      for (int i=0 ; i<2*n+5 ; i++){
            G[i].clear();
            vis[i] = 0;
      }
}

ll mark(ll u)
{
      //show(u);
      ll cnt = 1;
      vis[u] = 1;
      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (vis[v]==0){
                  cnt+=mark(v);
            }
      }
      return cnt;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n);
            scl(m);

            clean();

            ll node = n+1;
            for (int i=1 ; i<=m ; i++){
                  ll x, y;
                  scl(x) , scl(y);
                  if (x==y)continue;
                  G[x].push_back(node);
                  G[node].push_back(x);
                  G[y].push_back(node);
                  G[node].push_back(y);

                  node++;
            }

            queue<ll> q;

            for (int i=1 ; i<=2*n ; i++){
                  if (G[i].empty())vis[i] = 1;
                  else if (G[i].size()==1)q.push(i);
            }

            //show(q.size());

            ll ans = 0;

            while(!q.empty()){
                  ll u = q.front();
                  q.pop();
                  if(vis[u]==0){
                        ll temp = mark(u);
                        ans+=((temp-1)/2);
                  }
            }

            for (int i=1 ; i<=2*n ; i++){
                  if (vis[i]==0){
                        //show(i);
                        ll temp = mark(i);
                        ans+=((temp/2)+1);
                  }
            }
            cout << ans << endl;
      }

      return 0;
}
