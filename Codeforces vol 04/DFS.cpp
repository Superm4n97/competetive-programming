#include<bits/stdc++.h>

using namespace std;

vector < int > G[100];
int vis[100] , n , m;

void DFS(int u)
{
      cout << u << " ";

      vis[u] = 1;
      for(int i=0 ; i<G[u].size() ; i++){

            int v = G[u][i];
            if (vis[v]==0){
                  DFS(v);
            }
      }
}

int main()
{
      for (int i=0 ; i<100 ; i++)vis[i] = 0;

      cout << "Nodes : ";
      cin >> n;
      cout << "Edge : ";
      cin >> m;

      for (int i=1 ; i<=m ; i++){

            int a,b;
            cin >> a >> b;

            G[a].push_back(b);
            G[b].push_back(a);
      }

      DFS(1);


      return 0;
}

/*
5
5
1 2
1 3
2 4
3 4
4 5
*/



