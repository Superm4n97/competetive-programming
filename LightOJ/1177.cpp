#include<bits/stdc++.h>
#define inf 10000000800000008
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int bfs(ll R[105][105] , ll parent[105], ll st, ll ed)
{
      ll vis[105];
      memset(vis,0,sizeof vis);

      queue<int>q;
      q.push(st);
      vis[st] = inf;

      while(!q.empty()){

            int u = q.front();
            q.pop();

            for (int i=1 ; i<=100; i++){
                  if (R[u][i]>0 && vis[i]==0){
                        vis[i] = min(vis[u],R[u][i]);
                        q.push(i);
                        parent[i] = u;
                  }
            }
      }
      return vis[ed];
}

ll fordFulkerson(ll cap[105][105],ll st, ll ed)
{
      ll R[105][105];
      for (int i=0 ;i<105 ; i++)
            for (int j=0 ; j<105 ; j++)R[i][j] = cap[i][j];

      ll parent[105] , flow = 0;

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

            ll M, W, cap[105][105];
            scanf("%lld %lld",&M,&W);
            memset(cap,0,sizeof cap);
            cap[1][2] = cap[2*M-1][2*M] = inf;

            for (int i=2 ; i<M ; i++){

                  ll a;
                  scanf("%lld",&a);
                  cap[2*i-1][2*i] = a;
            }
            for (int i = 1 ; i<=W ; i++){
                  ll a, b, c;
                  scanf("%lld%lld%lld",&a,&b,&c);
                  cap[2*a][2*b-1] = c;
                  cap[2*b][2*a-1] = c;
            }

            printf("Case %d: %lld\n",_t,fordFulkerson(cap,1,2*M));
      }
}
