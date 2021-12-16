#include <bits/stdc++.h>
#define ll              long long int
#define show(x)         cout << #x << " : " << x << endl
#define inf 10000000000000014

#define maxn            105

using namespace std;

ll A[maxn][maxn], dp[3][maxn][maxn][maxn] , n,m;

ll rec(ll type, ll row, ll col1, ll col2)
{
      if (dp[type][row][col1][col2]!=-1)return dp[type][row][col1][col2];
      if (row==n && col2!=m)return dp[type][row][col1][col2] = -inf;
      if (col1>=col2)return dp[type][row][col1][col2] = -inf;
      if (col2>m)return 0;
      if(row>n)return 0;

//      cout << type <<" "<<row<<" "<<col1<<" "<<col2 << endl;

      if (type==0){
            return dp[type][row][col1][col2]=max(rec(type,row,col1+1,col2),rec(1,row,col1,col2))+A[row][col1];
      }
      else {
            return dp[type][row][col1][col2]=max(rec(type,row,col1,col2+1),rec(0,row+1,col1,col2))+A[row][col2];
      }
}

void clean()
{
      for (int i=0 ; i<n+3 ; i++){
            for (int j=0 ; j<m+3 ; j++){
                  for (int k=0 ; k<m+3 ; k++){
                        dp[0][i][j][k] = dp[1][i][j][k] = -1;
                  }
            }
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            //memset(dp,-1,sizeof dp);
            scanf("%lld %lld",&n,&m);
            clean();

            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++)scanf("%lld",&A[i][j]);
            }

            ll ans = rec(1,1,1,2)+A[1][1];

            printf("Case %d: %lld\n",_t,ans);
      }


      return 0;
}

/**
4

*/
