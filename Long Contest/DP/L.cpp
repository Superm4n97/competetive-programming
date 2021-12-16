#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005
#define mod 100000007

using namespace std;

ll n,k,s;
ll dp[15*maxn] , csum1[15*maxn], csum2[15*maxn];

ll solve()
{
      memset(dp,0,sizeof dp);
      for (ll i=1 ; i<=k ; i++)dp[i] = i;

      for (int i=2; i<=n ; i++){
            for (ll j=1 ; j<=s ; j++){
                  csum1[j] = (dp[j]+csum1[j-1])%mod;
                  csum2[j] = (csum1[j-1]+csum2[j-1])%mod;
            }
            for (ll j=1 ; j<=s ; j++){
                  dp[j] = csum2[j];
                  if (j>k){
                        dp[j] = (dp[j] - (csum2[j-k]+csum1[j-k-1]*k)%mod + mod)%mod;
                  }
            }
      }
      return dp[s];
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc; _t++){
            scanf("%lld %lld %lld",&n,&k,&s);
            printf("Case %d: %lld\n",_t,solve());
      }

      return 0;
}
