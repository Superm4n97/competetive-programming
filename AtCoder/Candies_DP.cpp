#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define mod 1000000007
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,K , dp[105][maxn] , prefixSum[105][maxn], A[maxn];

ll rec(ll pos, ll rem);

ll findPreSum(ll pos, ll rem)
{
      if (prefixSum[pos][rem] != -1)return prefixSum[pos][rem];
      if (rem==0)return prefixSum[pos][rem] = rec(pos,rem);
      else return prefixSum[pos][rem] = (rec(pos,rem) + findPreSum(pos,rem-1))%mod;
}

ll rec(ll pos, ll rem)
{
      if (dp[pos][rem] != -1)return dp[pos][rem];
      if (pos==n-1){
            if (A[pos]>=rem)return dp[pos][rem] = 1;
            return dp[pos][rem] = 0;
      }


      ll ret = 0, l = rem-A[pos]-1;
      if (l<0)ret = findPreSum(pos+1,rem);
      else ret = (findPreSum(pos+1,rem) - findPreSum(pos+1,l)+mod) % mod;

      //cout << pos << " : " << rem << " : " << ret << endl;

      return dp[pos][rem] = ret;
}

int main()
{
      scanf("%lld %lld",&n,&K);
      for (int i=0 ; i<n ; i++)scanf("%lld",&A[i]);

      memset(dp,-1,sizeof dp);
      memset(prefixSum,-1,sizeof prefixSum);

      ll ans = rec(0,K);
      printf("%lld\n",ans);

      return 0;
}

/*
3 4
1 2 3

2 0
0 0


1 1
2


*/
