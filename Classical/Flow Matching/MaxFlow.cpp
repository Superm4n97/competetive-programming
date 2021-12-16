/**max flow for undirected graph - O(N^3)**/
#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 105
#define inf 10000000000000016

using namespace std;

void printArray(ll R[maxn][maxn])
{
      for (int i=1 ; i<=4 ; i++){
            for (int j=1 ; j<=4 ; j++)cout << R[i][j] << " ";
            cout << endl;
      }
}

ll bfs(ll R[maxn][maxn], ll parent[maxn], ll start, ll finish)
{
      ll visited[maxn];
      memset(visited,0,sizeof visited);

      queue <ll> q;
      q.push(start);
      visited[start] = inf;

      while(!q.empty()){

            ll u = q.front();
            q.pop();

            for (int i=0 ; i<maxn ; i++){
                  if (R[u][i]>0 && visited[i]==0){

                        q.push(i);
                        parent[i] = u;
                        visited[i]  = min(visited[u],R[u][i]);
                  }
            }
      }
      return visited[finish];
}

ll fordFulkerson(ll Cap[maxn][maxn],ll start, ll finish)
{
      ll R[maxn][maxn];
      memset(R,0,sizeof R);

      for (int i=0 ; i<maxn ; i++){
            for (int j=0; j<maxn ; j++){
                  R[i][j] = Cap[i][j];
            }
      }

      ll parent[maxn] , flow = 0;
      while(true){

            ll path_flow = bfs(R,parent,start,finish);
            if (path_flow==0)break;

            ll v = finish;
            while(v!=start){

                  ll u = parent[v];

                  R[u][v] -= path_flow;
                  R[v][u] += path_flow;
                  v = u;
            }
            flow+=path_flow;
      }

      return flow;
}

int main()
{
      /**create capacity graph then call fordFulkerson() function**/
      ll tc;
      cin >> tc;

      for (int _t = 1 ; _t<=tc ; _t++){
            ll Cap[maxn][maxn];
            memset(Cap,0,sizeof Cap);

            ll n,m , st,fi;
            cin >> n;
            cin >> st >> fi >> m;
            for (int i=0 ; i<m ; i++){
                  ll a,b,c;
                  cin >> a >> b >> c;

                  Cap[a][b] += c;
                  Cap[b][a] += c;///for directed graph remove this edge
            }
            cout << "Case "<<_t<<": " <<fordFulkerson(Cap,st,fi) << "\n";
      }

      return 0;
}
