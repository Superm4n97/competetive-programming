#include <bits/stdc++.h>
#define ll              long long int
#define show(x)         cout << #x << " : " << x << endl
#define maxn 300005
#define inf 10000000000000016

using namespace std;

struct node
{
      ll child, weight;
};

vector < node > G[maxn];
ll n,m ,k , D[maxn] , P[maxn] , indegree[maxn] , X[maxn] , Y[maxn] , vis[maxn];
vector < pair <ll ,ll > > ans;

void diajkstra()
{
      priority_queue < pair < ll, ll > > pq;
      pq.push({0,1});
      D[1] = 0;

      while(!pq.empty()){

            ll u = pq.top().second;
            pq.pop();

            if (vis[u]==1)continue;
            else vis[u] = 1;

            for (int i=0 ; i<G[u].size() ; i++){

                  ll v = G[u][i].child , c = G[u][i].weight;
                  if (D[v]>D[u]+c){

                        D[v] = D[u]+c;
                        pq.push({-D[v],v});

                        P[v] = u;
                  }
            }
      }
}

int main()
{
      scanf("%I64d %I64d %I64d",&n,&m,&k);

      for (int i=1 ; i<=m ; i++){
            ll a, b,c;
            scanf("%I64d %I64d %I64d",&a,&b,&c);

            node aa,bb;
            aa.child = b;
            aa.weight = c;
            bb.child = a;
            bb.weight = c;

            G[a].push_back(aa);
            G[b].push_back(bb);

            X[i] = a;
            Y[i] = b;
      }

      for (int i=0 ; i<=n+3 ; i++)D[i] = inf;

      diajkstra();

      queue < ll > q;
      for (int i=1 ; i<=n ; i++)indegree[P[i]]++;

      for (int i=1 ; i<=n ; i++){
            if (indegree[i]==0)q.push(i);
      }

      while(!q.empty()){
            ll a = q.front();
            q.pop();

            if (a!=1){
                  ans.push_back({a,P[a]});

                  indegree[P[a]]--;
                  if (indegree[P[a]]==0)q.push(P[a]);
            }
      }

      memset(P,0,sizeof P);

      for (int i=0 ; i<ans.size() && i<k ; i++){
            ll id = ans.size()-i-1;
            P[ans[id].first] = ans[id].second;
      }

      printf("%I64d\n",min((ll)ans.size(),k));

      for (int i=1 ; i<=m ; i++){
            if (P[X[i]]==Y[i] || P[Y[i]]==X[i])printf("%I64d ",i);
      }



      return 0;
}
/**

*/
