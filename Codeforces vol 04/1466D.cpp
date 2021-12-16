#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 100005

using namespace std;

vector<ll> G[maxn] , vc;
ll n , W[maxn];

void clean()
{
     for (int i=0 ; i<n+3 ; i++){
            G[i].clear();
     }
     vc.clear();
}

void dfs(ll u, ll p)
{
      if (u==1 && G[u].size()==1){
            dfs(G[u][0],u);
            return;
      }

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (u==1 && i==0){
                  dfs(v,u);
            }
            else {
                  if (v!=p){
                        vc.push_back(W[u]);
                        dfs(v,u);
                  }
            }
      }
      return;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n);
            clean();

            ll sum = 0;

            for (int i=1 ; i<=n ; i++){
                  scl(W[i]);
                  sum+=W[i];
            }

            for (int i=1 ; i<n ; i++){
                  ll a,b;
                  scl(a);
                  scl(b);

                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            dfs(1,0);

            if (!vc.empty())sort(vc.rbegin(),vc.rend());

//            for (int i=0 ; i<vc.size() ; i++)cout << vc[i] << " ";
//            cout << endl;

            cout << sum << " ";
            for (int i=0 ; i<n-2 ; i++){
                  cout << sum+vc[i] << " ";
                  sum+=vc[i];
            }
            cout << "\n";
      }


      return 0;
}
