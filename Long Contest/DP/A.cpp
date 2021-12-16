#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000

using namespace std;

ll dp[105][105], n,k;

ll rec(ll pos, ll rem)
{
      if (rem==0 || pos==n)return 1;
      if (dp[pos][rem]!=-1)return dp[pos][rem];
      return dp[pos][rem] = (rec(pos+1,rem)+rec(pos,rem-1))%mod;
}

int main()
{
      while(true){
            scanf("%lld %lld",&k,&n);
            if (n==0 && k==0)break;
            memset(dp,-1,sizeof dp);
            printf("%lld\n",rec(1,k));
      }

      return 0;
}
/*
0 0 1
0 1 0
1 0 0
*/
