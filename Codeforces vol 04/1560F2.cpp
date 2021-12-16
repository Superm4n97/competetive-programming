#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 100000000000014

using namespace std;

ll n,k,dp[13][1050][3], dig[13];

ll rec(ll pos, ll mask, ll large)
{
      if (dp[pos][mask][large] != -1)return dp[pos][mask][large];

      if (!large){
            ll temp =
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld %lld",&n,&k);
            memset(dp,-1,sizeof dp);
            for (int i=11 ;i>=0 ; i--){
                  dig[i] = n%
            }
      }

      return 0;
}

/*
4
1 1
221 2
221 1
177890 2
*/
