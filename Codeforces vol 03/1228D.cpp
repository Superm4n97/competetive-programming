#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll n,m ,C[maxn] , vis[maxn] , dp[maxn][5];
vector < ll > G[maxn];

ll rec(ll node , ll color)
{
      if (dp[node][color] != -1)return dp[]
}

int main()
{
      memset(dp,-1,sizeof dp);

      cin >> n >> m;

      for (int i=0 ; i<m ; i++){
            ll a,b;
            cin >> a >> b;

            G[a].push_back(b);
            G[b].push_back(a);
      }

      for (int i=1;  i<=n ; i++){
            if (vis[i]==0){

            }
      }


      return 0;
}
