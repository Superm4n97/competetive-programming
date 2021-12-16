#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000

using namespace std;

ll dp[105][50005], n,A[105] , sum;

ll rec(ll pos, ll rem)
{
      if (dp[pos][rem] != -1) return dp[pos][rem];
      if (pos==n+1)return dp[pos][rem] = rem;

      if (A[pos]>rem)return dp[pos][rem] = rec(pos+1,rem);
      else return dp[pos][rem] = min(rec(pos+1,rem),rec(pos+1,rem-A[pos]));
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld",&n);
            sum = 0;
            memset(dp,-1,sizeof dp);

            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  sum+=A[i];
            }
            ll mid = sum/2;
//            show(rec(1,mid));
            ll ans = (sum-mid+rec(1,mid)) - (mid-rec(1,mid));
            printf("%lld\n",ans);
      }

      return 0;
}
/*
3
3
1 2 2
3
2 3 5
4
1 2 4 6
*/
