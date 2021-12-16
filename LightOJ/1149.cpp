#include<bits/stdc++.h>
#define inf 10000000800000008
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 205

using namespace std;

int bfs(ll R[maxn][maxn] , ll parent[maxn], ll st, ll ed)
{
      ll vis[maxn];
      memset(vis,0,sizeof vis);

      queue<int>q;
      q.push(st);
      vis[st] = inf;

      while(!q.empty()){

            int u = q.front();
            q.pop();

            for (int i=0 ; i<maxn; i++){
                  if (R[u][i]>0 && vis[i]==0){
                        vis[i] = min(vis[u],R[u][i]);
                        q.push(i);
                        parent[i] = u;
                  }
            }
      }
      return vis[ed];
}

ll fordFulkerson(ll cap[maxn][maxn],ll st, ll ed)
{
      ll R[maxn][maxn];
      for (int i=0 ;i<maxn ; i++)
            for (int j=0 ; j<maxn ; j++)R[i][j] = cap[i][j];

      ll parent[maxn] , flow = 0;

      while(true){
            ll pathFlow = bfs(R,parent,st,ed);
            if (pathFlow==0)break;

            flow+=pathFlow;
            ll v = ed;

            while(v!=st){

                  ll u = parent[v];
                  R[u][v]-=pathFlow;
                  R[v][u]+=pathFlow;
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

            ll A[105] , B[105] , n,m , st = 201, ed = 202;
            scanf("%lld",&n);
            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  cap[st][i] = 1;
            }
            scanf("%lld",&m);
            for (int i=1 ; i<=m ; i++){
                  scanf("%lld",&B[i]);
                  cap[i+100][ed] = 1;
            }

            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++){
                        if (B[j]%A[i]==0)cap[i][j+100] = 1;
                  }
            }

            printf("Case %d: %lld\n",_t,fordFulkerson(cap,st,ed));
      }
}
