#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string A,B;
ll dp[5005][5005] , n , m, ans = 0;

ll rec(ll x, ll y)
{
      if (dp[x][y] != -1)return dp[x][y];

      if (x==n-1 && y==m-1){
            if (A[x]==B[y]) dp[x][y] = 2;
            else  dp[x][y] = 0;

            ans = max(ans,dp[x][y]);
            return dp[x][y];
      }

      ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;

      if (A[x]==B[y])t1 = rec(x+1,y+1)+2;

      if (x<n-1) t2 = rec(x+1,y)-1;
      if (y<m-1) t3 = rec(x,y+1)-1;

      dp[x][y] = max(max(t1,0LL),max(t2,t3));

      ans = max(ans,dp[x][y]);

      return dp[x][y];
}

int main()
{
      scanf("%I64d %I64d",&n,&m);
      cin >> A >> B;

      memset(dp,-1,sizeof dp);

      ll temp = rec(0,0);

      printf("%I64d\n",ans);

      return 0;
}
