#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

vector<ll> dif;

ll n, m;
ll dp[505][505][35] , A[505][505];

ll rec(ll i, ll j, ll id)
{
      if (dp[])
}

int main()
{
      for (ll i=1 ; i*i*i*i < 1000000 ; i++){
            dif.push_back(i*i*i*i);
      }
//      show(dif.size());
      scl(n), scl(m);
      for (int i = 1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++)scl(A[i][j]);
      }

      memset(dp,-1,sizeof dp);

      ll ans = 0;

      for (int i=0 ; i<31 ; i++){
            ans = max(ans,rec(1,1,i));
      }

      if (ans==0)



      return 0;
}
