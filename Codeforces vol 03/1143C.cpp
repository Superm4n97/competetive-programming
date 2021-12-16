#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll n ,root , C[maxn];
vector < ll > G[maxn] , del;

void dfs(ll u, ll p)
{
      ll good = 0;

      //show(u);

      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];
            if (v!=p){

                  if (C[v]==0)good++;
                  dfs(v,u);
            }
      }

      if (good==0 && C[u]==1)del.push_back(u);

      return;
}

int main()
{
      cin >> n;
      for (int i=1 ; i<=n ; i++){

            ll a,c;
            cin >> a >> C[i];

            if (a==-1){
                  root = i;
            }
            else {
                  G[i].push_back(a);
                  G[a].push_back(i);
            }
      }

      dfs(root,-1);

      if (del.empty())cout << -1 << endl;
      else {
            sort(del.begin(),del.end());
            for (int i=0 ; i<del.size() ; i++)cout << del[i] << " ";
            cout << endl;
      }

      return 0;
}
