#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 205
#define inf 10000000000000016

using namespace std;

ll bfs(ll R[maxn][maxn], ll *parent, ll st, ll fn)
{
      ll visited[maxn];
      memset(visited,0,sizeof visited);

      queue<ll> q;
      q.push(st);
      visited[st] = inf;

      while(!q.empty()){

            ll u = q.front();
            q.pop();

            for (int i=0 ; i<maxn ; i++){
                  if (R[u][i]>0 && visited[i]==0){

                        visited[i] = min(visited[u],R[u][i]);
                        q.push(i);
                        parent[i] = u;
                  }
            }
      }

      return visited[fn];
}

ll fordFulkerson(ll cap[maxn][maxn] , ll st, ll fn)
{
      ll R[maxn][maxn] , parent[maxn];
      memset(R,0,sizeof R);

      for (int i=0 ; i<maxn ; i++){
            for (int j=0 ; j<maxn ; j++)R[i][j] = cap[i][j];
      }

      ll flow = 0;

      while(true){

            ll path_flow = bfs(R,parent,st,fn);
            if (path_flow==0)break;

            flow+=path_flow;

            ll v = fn;
            while(v!=st){

                  ll u = parent[v];
                  R[u][v] -= path_flow;
                  R[v][u] += path_flow;
                  v = u;
            }
      }

      return flow;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){

            ll cap[maxn][maxn];
            memset(cap,0,sizeof cap);

            ll n;
            scanf("%lld",&n);
            for (int i=1 ; i<=n ; i++){

                  ll a;
                  scanf("%lld",&a);
                  cap[2*i-1][2*i] = a;
            }

            int m;
            scanf("%d",&m);

            for (int i=1;  i<=m ; i++){

                  ll a, b, c;
                  scanf("%lld %lld %lld",&a,&b,&c);

                  cap[2*a][2*b-1] = c;
            }

            ll st = 202 , fn = 203;
            ll B, D;
            scanf("%lld %lld",&B,&D);

            for (int i=0 ; i<B+D ; i++){

                  ll a;
                  scanf("%lld",&a);

                  if (i<B)cap[st][2*a-1] = inf;
                  else cap[2*a][fn] = inf;
            }

            printf("Case %d: %lld\n",_t,fordFulkerson(cap,st,fn));
      }

      return 0;
}
