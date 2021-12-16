#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

//    r    c   m  chosen
ll dp[71][71][71][36];
ll A[71][71] , n , m, k;

ll rec(ll row, ll col, ll md, ll chosen)
{
      if (row>n){
            if (md==0)return 0;
            else return -2;
      }
      if (dp[row][col][md][chosen] != -1)return dp[row][col][md][chosen];


}

int main()
{
      scanf("%I64d %I64d %I64d",&n,&m,&k);
      for (int i=1 ; i<=n ; i++){
            for (int j = 1 ; j<=m ; j++)scanf("%I64d",&A[i][j]);
      }

      memset(dp,-1,sizeof dp);



      return 0;
}
