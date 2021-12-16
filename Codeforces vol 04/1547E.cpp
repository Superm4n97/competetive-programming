#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define maxn 300005
#define inf 100000000000000000

using namespace std;

ll n,k,vis[maxn] , x[maxn] , y[maxn];

void clean()
{
      for (int i=0 ; i<=n+3 ; i++){
            vis[i] = inf;
      }
}

ll valid(ll id)
{
      if (id>=1 && id<=n)return true;
      return false;
}

void bfs()
{
      priority_queue<pair<ll,ll> > pq;
      for (int i=1 ; i<=k ; i++){
            vis[x[i]] = y[i];
            pq.push({-y[i],x[i]});
      }

      while(!pq.empty()){
            ll id = pq.top().second;
            pq.pop();

            if (valid(id+1) && vis[id+1]>vis[id]+1){
                  vis[id+1] = vis[id]+1;
                  pq.push({-vis[id+1],id+1});
            }
            if (valid(id-1) && vis[id-1]>vis[id]+1){
                  vis[id-1] = vis[id] + 1;
                  pq.push({-vis[id-1],id-1});
            }
      }

      return;
}

int main()
{
      ll tc;
      scl(tc);
      while(tc--){
            scl(n) , scl(k);
            clean();

            for (int i=1 ; i<=k ; i++)scl(x[i]);
            for (int i=1 ; i<=k ; i++)scl(y[i]);

            bfs();
            for (int i=1 ; i<=n ; i++)printf("%lld ",vis[i]);
            printf("\n");
      }


      return 0;
}
