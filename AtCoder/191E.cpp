#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define maxn 2005

using namespace std;

ll n,m;
vector<ll> G[maxn] , W[maxn];

ll diakstra(ll s)
{
      priority_queue<pair<ll,ll> > pq;
      ll cost[n+5];
      memset(cost,-1,sizeof cost);

      for (ll i=0 ; i<(ll)G[s].size() ; i++){
            pq.push({-W[s][i],G[s][i]});
            if (cost[G[s][i]] == -1)cost[G[s][i]] = W[s][i];
            else cost[G[s][i]] = min(cost[G[s][i]],W[s][i]);
      }

      while(!pq.empty()){
            ll u = pq.top().second , gst = pq.top().first*-1;
            pq.pop();
            if (gst != cost[u])continue;

            if (u==s)return cost[s];

            for (ll i=0 ; i<(ll)G[u].size() ; i++){
                  ll v = G[u][i] , c = W[u][i];
                  if (cost[v] == -1){
                        cost[v] = cost[u]+c;
                        pq.push({-cost[v],v});
                  }
                  else if (cost[u]+c<cost[v]){
                        cost[v] = cost[u]+c;
                        pq.push({-cost[v],v});
                  }
            }
      }
      return -1;
}

int main()
{
      scanf("%lld %lld",&n,&m);
      for (ll i=0 ; i<m ; i++){
            ll a,b,c;
            scanf("%lld %lld %lld",&a,&b,&c);
            G[a].push_back(b);
            W[a].push_back(c);
      }

      for (ll i=1 ; i<=n ; i++){
            ll ans = diakstra(i);
            printf("%lld\n",ans);
      }

      return 0;
}
