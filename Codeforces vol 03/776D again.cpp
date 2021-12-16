#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << endl
#define maxn 200005

using namespace std;

int n,m,edgeColor[maxn] , nodeColor[maxn] , vis[maxn];
vector < int > edge[maxn] , G[maxn];
map < pair < ll,  ll> , ll > mp;

void dfs(int u)
{
      vis[u] = 1;

      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];

            if (!vis[v]){
                  if (edgeColor[mp[{u,v}]]==1){
                        nodeColor[v] = nodeColor[u];
                  }
                  else {
                        nodeColor[v] = 1-nodeColor[u];
                  }
                  dfs(v);
            }
      }
}

int main()
{
      cin >> n >> m;
      for(int i = 1; i<=n; i++)cin >> edgeColor[i];

      for (int i=1 ; i<=m ; i++){
            ll x;
            cin >> x;

            while(x--){
                  ll a;
                  cin >> a;
                  edge[a].push_back(i);
            }
      }

      for (int i=1 ; i<=n ; i++){
            G[edge[i][0]].push_back(edge[i][1]);
            G[edge[i][1]].push_back(edge[i][0]);

            mp[{edge[i][0] , edge[i][1]}] = i;
            mp[{edge[i][1] , edge[i][0]}] = i;
      }

      for (int i=0 ; i<=m ; i++){
            if(!vis[i]){
                  ///continue issue
                  nodeColor[i] = 0;
                  dfs(i);
            }
      }

      bool solution = true;

      for (int i=1 ; i<=n ; i++){
            if (edgeColor[i]==1 && nodeColor[edge[i][0]] != nodeColor[edge[i][1]])solution = false;
            if (edgeColor[i]==0 && nodeColor[edge[i][0]] == nodeColor[edge[i][1]]) solution = false;
      }

      cout << (solution?"YES":"NO") << endl;

      return 0;
}
