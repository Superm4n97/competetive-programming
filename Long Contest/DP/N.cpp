#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 16
#define maxMask 65536

using namespace std;

ll A[18][18] , n, dp[17][maxMask];

ll rec(ll pos, ll mask)
{
      if (pos==n)return 0;
      if (dp[pos][mask] != -1)return dp[pos][mask];
      ll ret = 0LL;
      for (ll i = 0LL ; i<n ; i++){
            ll p = (1LL<<i);
            if ((p&mask) == 0){
                  ret = max(ret,rec(pos+1,(mask|p))+A[pos][i]);
            }
      }
      return dp[pos][mask] = ret;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t =1 ; _t<=tc ; _t++){
            scanf("%lld",&n);
            for (int i=0 ; i<n ; i++){
                  for (int j=0;j<n ; j++)scanf("%lld",&A[i][j]);
            }
            memset(dp,-1,sizeof dp);
            printf("Case %d: %lld\n",_t,rec(0,0));
      }

      return 0;
}
