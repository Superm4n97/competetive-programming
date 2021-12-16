#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m;
vector < ll > G[100005];
vector < pair<pair <ll,ll> , ll > > vp;

int main()
{
      cin >> n >> m;
      for (int i=1 ; i<=m ; i++){
            ll a, b , w;
            cin >> a >> b >> w;

            vp.push_back({{a,b},w});
      }

      ll b = 1 , e = 10000000010 , ans = 10000000010 , maxn = n+n+5;

      while(b<=e){

            ll mid = (b+e)/2;

            for (int i=0 ; i<=maxn ; i++){
                  G[i].clear();
            }

            for (int i=0 ; i<vp.size() ; i++){
                  if (vp[i].second<=mid){

                        ll a = vp[i].first.first , b = vp[i].first.second + n;

                        G[a].push_back(b);
                        G[b].push_back(a);
                  }
            }

            ll vis[maxn] , totalA = 0 , totalB = 0;
            memset(vis,0,sizeof vis);

            bool sol = true;

            for (int i=1 ; i<=n ; i++){
                  if (vis[i]==0){

                        queue < pair<ll,ll> > q;
                        q.push({i,0});
                        vis[i] = 1;

                        ll even = 0, odd = 0;

                        while(!q.empty()){
                              ll u = q.front().first , level = q.front().second;
                              q.pop();

                              if (level%2)odd++;
                              else even++;

                              for (int j=0 ; j<G[u].size() ; j++){
                                    ll v = G[u][j];

                                    if (vis[v]==0){
                                          vis[v] = 1;
                                          q.push({v,level+1});
                                    }
                              }
                        }

                        if(even!=odd)sol = false;
                  }
            }

            if (sol){
                  ans = min(ans,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }

      if (ans == 10000000010)cout << -1 << endl;
      else cout << ans << endl;

      return 0;
}
