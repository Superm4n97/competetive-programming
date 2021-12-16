#include<bits/stdc++.h>
#define ll long long int
#define maxn 1005
#define inf 100000000000014
#define show(x) cout << #x << " : " << x <<endl

using namespace std;

ll n,m,k , cost[maxn][maxn];
vector <ll> G[maxn], W[maxn];
vector <pair <ll,ll> > vp , E;

void bfs(ll s)
{
      //show(s);
      for (int i=0 ; i<=n ; i++)cost[s][i] = inf;

      priority_queue <pair<ll,ll> > pq;
      pq.push({0,s});
      cost[s][s] =  0;

      while(!pq.empty()){

            ll u = pq.top().second , d = -pq.top().first;
            pq.pop();

            if (d != cost[s][u])continue;

            for (int i=0 ; i<G[u].size() ; i++){

                  ll v = G[u][i] , c = W[u][i];
                  if (cost[s][v]>cost[s][u]+c){

                        cost[s][v] = cost[s][u]+c;
                        pq.push({-cost[s][v],v});
                  }
            }
      }
}

int main()
{
      cin >> n >> m >> k;
      for (int i=0; i<m ; i++){

            ll a,b,c;
            cin >> a >>b >> c;

            G[a].push_back(b);
            G[b].push_back(a);

            E.push_back({a,b});

            W[a].push_back(c);
            W[b].push_back(c);
      }

      for (int i=0 ; i<k ; i++){

            ll a,b;
            cin >> a >> b;
            vp.push_back({a,b});
      }

      for (ll i=1 ; i<=n ; i++){
            bfs(i);
      }

      //show(n);

      ll ans = inf;

      for (int i=0 ; i<E.size() ; i++){

            ll a = E[i].first , b = E[i].second , sum = 0;
            for (int j=0 ; j<vp.size() ; j++){

                  ll x = vp[j].first , y = vp[j].second;
                  sum += min(cost[x][y],min(cost[a][x]+cost[b][y] , cost[b][x]+cost[a][y]));
            }
            ans = min(ans,sum);
      }

      cout << ans << "\n";

      return 0;
}
