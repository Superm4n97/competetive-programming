#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int

using namespace std;

vector < ll > G[25];
ll vis[25][25];

void clean()
{
      memset(vis,0,sizeof vis);
      for (int i=0; i<24 ; i++){
            G[i].clear();
      }
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            clean();

            ll n;
            string s,t;
            cin >> n >> s >> t;

            bool sol = true;

            for (int i=0 ; i<n ; i++){
                  if (s[i]>t[i])sol = false;
                  if (s[i]<t[i]){
                        ll a = s[i]-'a' , b = t[i] - 'a';
                        if (vis[a][b]==0){
                              G[a].push_back(b);
                              vis[a][b] = 1;
                        }
                  }
            }
            if (!sol){
                  cout << -1 << endl;
                  continue;
            }

            ll ans = 0;

            for (int i=0 ; i<20 ; i++){
                  if (G[i].empty())continue;

                  sort(G[i].begin(), G[i].end());

                  ll u = G[i][0];
                  ans++;

                  for (int j = 1 ; j<G[i].size() ; j++){
                        ll v = G[i][j];
                        if (vis[u][v]==0){
                              G[u].push_back(v);
                              vis[u][v] = 1;
                        }
                  }
            }

            cout << ans << endl;
      }

      return 0;
}
