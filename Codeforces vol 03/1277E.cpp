#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 500005

using namespace std;

vector < ll > G[maxn];
ll vis[maxn] , aa,bb,n,m , cnt , ans;

void clean()
{
      ans = 0;
      for (int i=0 ; i<=n; i++){
            G[i].clear();
            vis[i] = 0;
      }
}


void dfs(ll u)
{
      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];

            if (!vis[v]){
                  vis[v] = 1;
                  cnt++;
                  dfs(v);
            }
      }
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n >> m >> aa >> bb;

            clean();

            for (int i=0 ; i<m;i++){

                  ll a,b;
                  cin >> a >> b;

                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            vis[aa] = vis[bb] = 1;
            cnt = 2;
            dfs(aa);
            ans = (n - cnt);

            //show(cnt);

            for (int i=0 ; i<=n;i++)vis[i] = 0;

            vis[aa] = vis[bb] = 1;
            cnt = 2;
            dfs(bb);

            ans*=(n-cnt);

            cout << ans << endl;
      }


      return 0;
}
