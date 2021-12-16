#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 4194303
//#define maxn 16777216
//#define maxn 127

using namespace std;
/*11111
00101

11010*/

int dp[maxn+5] , mp[maxn+5] , n , A[1000006];

int rec(int mask)
{
//      show(mask);
      if (dp[mask] != -1)return dp[mask];
      if (mask==0 || mp[mask]){
            return dp[mask] = mp[mask];
      }
//      show(mask);

      int ret = 0;
      for (int i=0 ; i<=22 ; i++){
            if ((mask&(1<<i))){
                  ret = max(ret,rec(mask^(1<<i)));
            }
      }

      return dp[mask] = ret;
}

int main()
{
//      cout << (1<<22)-1;
      memset(dp,-1,sizeof dp);

      scanf("%d",&n);
      for (int i=1 ; i<=n ; i++){
            scanf("%d",&A[i]);
            mp[A[i]] = i;
      }

      for (int i=1 ;i<=n ; i++){
            int x = rec((maxn^A[i]));
            if (x!=0)printf("%d ",A[x]);
            else printf("-1 ");
      }
      printf("\n");

      return 0;
}
