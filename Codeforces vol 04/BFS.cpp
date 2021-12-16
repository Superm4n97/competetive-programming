#include<bits/stdc++.h>

using namespace std;

vector<int> G[100];
int vis[100];
queue < int > q;

void BFS()
{
      for (int i=0; i<100 ; i++)vis[i] = 0;

      q.push(1);
      vis[1] = 1;

      while(!q.empty()){

            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int i=0 ; i<G[u].size() ; i++){

                  int v = G[u][i];

                  if (vis[v]==0){

                        q.push(v);
                        vis[v] = 1;
                  }
            }
      }
}

int main()
{
      int n , m;
      cout << "Number of Node: ";
      cin >> n;

      cout << "Number of Edge: ";
      cin >> m;

      for (int i=1 ; i<=m ; i++){
            int a,b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
      }

      BFS();


      return 0;
}

/*
5
6
1 2
1 3
2 4
3 4
3 5
4 5
*/
