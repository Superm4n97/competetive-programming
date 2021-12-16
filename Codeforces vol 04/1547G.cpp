#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define maxn 400005

using namespace std;

ll n , m , path[maxn], indegree[maxn] , reachable[maxn] , selfloop[maxn];
vector<ll> G[maxn];

void clean()
{
      for (int i=0 ; i<n+3 ; i++){
            G[i].clear();
            indegree[i] = path[i] = reachable[i] = selfloop[i] = 0;
      }
}

void connect(ll u)
{
      reachable[u] = 1;
      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            indegree[v]++;
            if (reachable[v] == 0){
                  connect(v);
            }
      }
}

void degree()
{
      if (indegree[1] != 0)return;
      queue<ll> q;
      q.push(1);
      path[1] = 1;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];

                  path[v]+=path[u];
                  if (path[v]>1)path[v] = 2;
                  indegree[v]--;
                  if (indegree[v]==0){
                        q.push(v);
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
            for (int i=0 ; i<m ; i++){
                  ll a, b;
                  scl(a) , scl(b);

                  G[a].push_back(b);
            }
            connect(1);
            degree();

            for (int i=1 ; i<=n ; i++){
                  if (reachable[i]==0)printf("0 ");
                  else if (indegree[i])printf("-1 ");
                  else if (path[i]==1)printf("1 ");
                  else printf("2 ");
            }
            printf("\n");
      }


      return 0;
}
/*
1
6 6
1 2
1 3
2 4
4 3
3 5
3 6
*/
