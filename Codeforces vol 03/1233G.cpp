#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1004
#define inf 10000000000000016

using namespace std;

ll n, m, k , occ[maxn] , dis[maxn];
vector <pair<ll,ll> > E ;
vector < ll > G,W;
map < pair<ll,ll> , ll > mp;

void findPath(ll u)
{
      for (int i=0 ; i<)
}

ll sol(ll x, ll y)
{
      memset(parent,-1,sizeof parent);
      memset(occ,0,sizeof occ);
      for (int i=0 ; i<=n ; i++)dis[i] = inf;

      priority_queue< pair<ll,ll> > pq;

      pq.push({0,x});
      dis[x] = 0;

      while(!pq.empty()){

            ll d = pq.top().first , u = pq.top().second;

            for (int i=0 ; i<G[u].size() ; i++){

                  ll v = G[u][i] , c = W[u][i];
                  if (dis[v]>dis[u]+c){

                        dis[v] = dis[u]+c;
                        pq.push({dis[v],v});
                  }
            }
      }

      findpath
}

int main()
{
      scanf("%I64d %I64d %I64d",&n,&m,&k);
      for (int i=1 ; i<=m ; i++){

            ll a, b, c;
            scanf("%I64d %I64d %I64d",&a,&b,&c);
            E.push_back({min(a,b),max(a,b)});

            G[a].push_back(b);
            G[b].push_back(a);

            W[a].push_back(c);
            W[b].push_back(c);
      }

      for (int i=0 ; i<m ; i++){
            sol(E[i].first , E[i].second);
      }

      return 0;
}
