#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

vector < ll > G[maxn];
ll n , A[maxn] , C[maxn] , mxChild[maxn] , sum[maxn];

void dfs(ll u, ll p)
{

      if (G[u].size()==1 && u!=1){
            C[u] = 1;
            sum[u] = A[u];
            mxChild[u] = A[u];

            return;
      }

      sum[u] = A[u];
      ll mx = 0;

      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];
            if (v==p) continue;

            dfs(v,u);

            sum[u]+=sum[v];

            mx = max(mx,mxChild[v]);
            C[u]+=C[v];
      }

      ll temp = sum[u]/C[u];
      if (sum[u]%C[u])temp++;

      mxChild[u] = max(mx,temp);
}

int main()
{
      cin >> n;
      for (int i=2 ; i<=n ; i++){

            ll a;
            cin >> a;
            G[a].push_back(i);
            G[i].push_back(a);
      }
      for (int i=1 ; i<=n ; i++)cin >> A[i];

      dfs(1,0);

      cout << mxChild[1] << "\n";


      return 0;
}

