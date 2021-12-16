#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[105][105][105], A[105][105],n,m,k;

ll rec(ll x, ll y, ll mv)
{
      if (dp[x][y][mv]!=-1)return dp[x][y][mv];
      ll rx = mv-(x-1)+1, ry = mv-(y-1)+1;
      if (rx==ry && x==y)return dp[x][y][mv] = 0;
      if (rx==n+1 || ry==n+1 || x==m+1 || y==m+1)return dp[x][y][mv] = 0;

      ll ret = rec(x,y,mv+1);
      ret = max(ret,rec(x+1,y,mv+1));
      ret = max(ret,rec(x,y+1,mv+1));
      ret = max(ret,rec(x+1,y+1,mv+1));

      return dp[x][y][mv] = ret+A[rx][x]+A[ry][y];
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            scanf("%lld %lld",&n,&m);
            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++)scanf("%lld",&A[i][j]);
            }
            memset(dp,-1,sizeof dp);
            printf("Case %d: %lld\n",_t,rec(1,2,1)+A[1][1]+A[n][m]);
      }

      return 0;
}

//11 12 13 14 15 16 17
//21 22 23 24 25 26
//31 32 33 34 35 36
//41 42 43 44 45 46
//51 52 53 54 55 56
