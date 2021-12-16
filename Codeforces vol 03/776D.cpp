#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

///total nodes m , total edge n
ll initial[maxn] , edge[maxn][4] , vis[maxn] , C[maxn] , n,m;
vector < ll > G[maxn];
map < pair < ll , ll > , ll > mp;
bool solution = true;

void dfs(ll u)
{
      vis[u] = 1;

      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];
            if (!vis[v]){

                  if (initial[mp[{u,v}]]==1)C[v] = C[u];
                  else C[v] = 1-C[u];
                  dfs(v);
            }
      }
}

int main()
{
      cin >> n >> m;
      for (int i=1 ; i<=n ; i++)cin >> initial[i];

      for (int i=1 ; i<=m ; i++){

            ll x;
            cin >> x;

            for (int j=1 ; j<=x ; j++){

                  ll a;
                  cin >> a;
                  if (edge[a][1] == 0)edge[a][1] = i;
                  else edge[a][2] = i;
            }
      }

      for (int i=1 ; i<=n ; i++){

            ll a = edge[i][1] , b = edge[i][2];
            G[a].push_back(b);
            G[b].push_back(a);
            mp[{a,b}] = i;
            mp[{b,a}] = i;
      }

      for (int i=1 ; i<=m ;i++){
            if (!vis[i]){

                  C[i] = 0;
                  dfs(i);
            }
      }

      for (int i=1; i<=n ; i++){
            if (initial[i]==1 && (C[edge[i][1]] != C[edge[i][2]]))solution = false;
            if (initial[i]==0 && (C[edge[i][1]] == C[edge[i][2]]))solution = false;
      }

      cout << (solution?"YES":"NO") << endl;



      return 0;
}
