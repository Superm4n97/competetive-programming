#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2005
#define inf 100000000000000017

using namespace std;

ll n,m,w, vis[maxn][maxn];
ll g[maxn][maxn],ans;
ll dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

vector<ll>portal_s, portal_y;

bool check(ll x, ll y)
{
      if (x>=1 && x<=n && y>=1 && y<=m && g[x][y] != -1)return true;
      return false;
}

//void reachable()
//{
//      priority_queue<pair<ll,pair<ll,ll> > > pq;
//      pq.push({0,{1,1}});
//      vis[1][1] = 0;
//      while(!pq.empty()){
//            ll x = pq.top().second.first , y = pq.top().second.second;
//            pq.pop();
//
//            for (int i=0 ; i<4 ; i++){
//                  ll a = x+dx[i], b = y+dy[i];
//                  if (check(a,b) && vis[a][b]>vis[x][y]+w){
//                        vis[a][b] = vis[x][y]+w;
//                        pq.push({-vis[a][b],{a,b}});
//                  }
//            }
//      }
//}

void portalSource()
{
      priority_queue<pair<ll,pair<ll,ll> > > pq;
      pq.push({0,{1,1}});
      vis[1][1] = 0;
      while(!pq.empty()){
            ll x = pq.top().second.first , y = pq.top().second.second;
            pq.pop();

            if (g[x][y]!=0)portal_s.push_back(vis[x][y]+g[x][y]);

            for (int i=0 ; i<4 ; i++){
                  ll a = x+dx[i], b = y+dy[i];
                  if (check(a,b) && vis[a][b]>vis[x][y]+w){
                        vis[a][b] = vis[x][y]+w;
                        pq.push({-vis[a][b],{a,b}});
                  }
            }
      }
}

void portalDestination()
{
      priority_queue<pair<ll,pair<ll,ll> > > pq;
      pq.push({0,{n,m}});
      vis[n][m] = 0;
      while(!pq.empty()){
            ll x = pq.top().second.first , y = pq.top().second.second;
            pq.pop();

            if (g[x][y]!=0)portal_y.push_back(vis[x][y]+g[x][y]);

            for (int i=0 ; i<4 ; i++){
                  ll a = x+dx[i], b = y+dy[i];
                  if (check(a,b) && vis[a][b]>vis[x][y]+w){
                        vis[a][b] = vis[x][y]+w;
                        pq.push({-vis[a][b],{a,b}});
                  }
            }
      }
}

void clean()
{
      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++)vis[i][j] = inf;
      }
}

int main()
{
      scanf("%lld %lld %lld",&n,&m,&w);

      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++)scanf("%lld",&g[i][j]);
      }

//      clean();
//
//      reachable();


      clean();
      portalSource();

      ans = vis[n][m];

      clean();
      portalDestination();

      if (!portal_s.empty())sort(portal_s.begin(),portal_s.end());
      if (!portal_y.empty())sort(portal_y.begin(),portal_y.end());

      if (!portal_s.empty() && !portal_y.empty())ans = min(ans,portal_s[0]+portal_y[0]);

      if (ans>=inf)ans = -1;

      printf("%lld\n",ans);



      return 0;
}
