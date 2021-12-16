#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 105
#define inf 10000000000000016

using namespace std;

ll bfs(ll R[maxn][maxn] ,ll parent[maxn] , ll st, ll fn)
{
      ll visited[maxn];
      memset(visited,0,sizeof visited);

      queue<ll> q;
      q.push(st);
      visited[st] = inf;

      while(!q.empty()){

            ll u = q.front();
            q.pop();
            //show(u);

            for (int i=0 ; i<maxn ; i++){
                  if (R[u][i] > 0  && visited[i]==0){

                        visited[i] = min(visited[u],R[u][i]);
                        parent[i] = u;
                        q.push(i);
                  }
            }
      }

      return visited[fn];
}

ll fordFulkerson(ll cap[maxn][maxn] , ll st, ll fn)
{
      ll R[maxn][maxn] , parent[maxn] , flow = 0;
      memset(R,0,sizeof R);

      for (int i=0 ; i<maxn ; i++)
            for (int j=0 ; j<maxn ; j++)R[i][j] = cap[i][j];

      while(true){

            ll path_flow = bfs(R,parent,st,fn);
            //show(path_flow);
            if (path_flow==0)break;

            ll v = fn;
            //cout << v << " ";
            while(v!=st){


                  ll u = parent[v];
                  R[u][v]-=path_flow;
                  R[v][u]+=path_flow;
                  v = u;

              //    cout << v << " ";
            }

            //cout << endl;

            flow+=path_flow;
      }

      return flow;
}

ll stringToInt(string s)
{
      if (s=="XXL")return 51;
      if (s=="XL")return 53;
      if (s=="L")return 55;
      if (s=="M")return 57;
      if (s=="S")return 59;
      if (s=="XS")return 61;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){

            ll n , m , st = 70 , fn = 71 , cap[maxn][maxn];
            memset(cap,0,sizeof cap);
            scanf("%lld %lld",&n,&m);

            for (int i=1 ; i<=m ; i++){

                  string s,t;
                  cin >> s >> t;

                  ll a = stringToInt(s) , b = stringToInt(t);

                  cap[st][i] = 1;
                  cap[i][a] = 1;
                  cap[i][b] = 1;
            }
            for (int i=51 ; i<=61 ; i+=2){
                  cap[i][i+1] = n;
                  cap[i+1][fn] = n;
            }
            ll ans = fordFulkerson(cap,st,fn);

            //show(ans);

            if (ans==m)printf("Case %d: YES\n",_t);
            else printf("Case %d: NO\n",_t);
      }


      return 0;
}
