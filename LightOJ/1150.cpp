#include<bits/stdc++.h>
#define inf 10000000800000008
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 30

using namespace std;

ll mp[maxn][maxn];

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

void makingMP()
{
      ll cnt = 1;
      for (int i=0; i<=27 ; i++){
            for (int j=0 ; j<=27; j++){
                  mp[i][j] = cnt;
                  cnt++;
            }
      }
}

int main()
{
      makingMP();
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){

            ll grid[maxn][maxn];
            memset(grid,0,sizeof grid);

            for (int i=0 ; i<n ; i++){
                  string s;
                  cin >> s;

                  for (int j = 0 ; j<=m ; j++){
                        if (s[j]=='#')grid[i][j] = 1;
                        else if (s[i]=='H')grid[i][j] = 2;
                        else if (s[i]=='G')grid[i][j] = 3;
                  }
            }

            ll b = 1,

            printf("Case %d: %lld\n",_t,fordFulkerson(cap,st,ed));
      }
}
