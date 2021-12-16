#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

vector < ll > G[maxn];
ll n , c[maxn] , A,B;

void clean()
{
      for (int i = 0 ; i<=n+3 ; i++){
            G[i].clear();
            c[i] = 0;
      }
      A = B = -1;
}

void dfs(ll u, ll p)
{
      c[u] = 1;

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v!=p){
                  dfs(v,u);

                  if (c[v]==n/2){
                        A = u;
                        B = v;
                  }

                  c[u]+=c[v];
            }
      }
}

ll fnd(ll u, ll p)
{
      if (G[u].size()==1)return u;

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v!=p){
                  return fnd(v,u);
            }
      }
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            cin >> n;

            clean();

            for (int i=1 ; i<n ; i++){
                  ll a, b;
                  cin >> a >> b;

                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            if (n%2){
                  cout << 1 << " " << G[1][0] << endl;
                  cout << 1 << " " << G[1][0] << endl;
                  continue;
            }

            dfs(1,-1);

            if (A==-1){
                  cout << 1 << " " << G[1][0] << endl;
                  cout << 1 << " " << G[1][0] << endl;
                  continue;
            }
            else {
                  ll x = fnd(A,B);
                  cout << G[x][0] << " " << x << endl;
                  cout << B<< " " << x << endl;
            }
      }


      return 0;
}
