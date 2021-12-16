#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define inf 100000000000000017
#define maxn 200005

using namespace std;

ll n ,m, dp[maxn][3] , dis[maxn];
vector<ll> G[maxn];

void clean()
{
      for (int i=0 ; i<=n+2 ; i++){
            G[i].clear();
            dp[i][0] = dp[i][1] = -1;
            dis[i] = inf;
      }
}

void bfs()
{
      dis[1] = 0;
      queue<ll> q;
      q.push(1);

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];
                  if (dis[v]>dis[u]+1){
                        dis[v] = dis[u]+1;
                        q.push(v);
                  }
            }
      }
      return;
}

ll rec(ll u, ll state)
{
      if(dp[u][state] != -1)return dp[u][state];
      ///base

      ll ret = dis[u];

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (dis[v]>dis[u])ret = min(ret,rec(v,state));
            else if (state==0){
                  ret = min(ret,rec(v,1));
            }
      }
      return dp[u][state] = ret;
}

int main()
{
      ll tc;
      scl(tc);
      while(tc--){
            scl(n);
            scl(m);
            clean();

            for (int i=1 ; i<=m ; i++){
                  ll a, b;
                  scl(a),scl(b);
                  G[a].push_back(b);
            }
            bfs();

            for (int i=1 ; i<=n ; i++){
                  ll temp = rec(i,0);
                  printf("%I64d ",temp);
            }
            printf("\n");
      }

      return 0;
}
