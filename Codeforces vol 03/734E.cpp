#include<bits/stdc++.h>
#define show(x) cout << #x" : " << x << endl
#define maxn 200005

using namespace std;

int color[maxn],source,source_depth = -1,n , ans = 0;
vector<int> G[maxn];

void findSource(int u, int parent, int level)
{
      if (level>source_depth){
            source_depth = level;
            source = u;
      }
      for (int i=0 ; i<G[u].size() ; i++){
            int v = G[u][i];
            if (v!=parent){
                  if (color[v]==color[u]) findSource(v,u,level);
                  else findSource(v,u,level+1);
            }
      }
}

void findResult(int u, int parent, int level)
{
      ans = max(ans,(level+1)/2);

      for (int i=0 ; i<G[u].size() ; i++){
            int v = G[u][i];
            if (v!=parent){
                  if (color[u]==color[v]) findResult(v,u,level);
                  else findResult(v,u,level+1);
            }
      }
}

int main()
{
      cin >>n;
      for (int i=1 ; i<=n ; i++)cin >> color[i];

      for (int i=1 ; i<n ; i++){
            int a,b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
      }
      findSource(1,0,0);
      findResult(source,0,0);

      cout << ans << "\n";


      return 0;
}
