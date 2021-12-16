#include<bits/stdc++.h>
#define ll long long int
#define maxn 5205
#define show(x) cout << #x << " : "  << x << endl

using namespace std;

ll dp[maxn][maxn],N , M;
/// dp should be indexed from 1

void make2dRangeDP()
{
      for (int i=1 ; i<=N ; i++){
            for (int j=1 ; j<=M ; j++){
                  dp[i][j] += dp[i][j-1];
            }
      }
      for (int j=1 ; j<=M ; j++){
            for (int i=1 ; i<=N ; i++){
                  dp[i][j]+=dp[i-1][j];
            }
      }
}

ll query(ll x1, ll y1, ll x2, ll y2)
{
      ///x1,y1 upper left corner: x2,y2 lower right corner x1<=x2, y1<=y2
      return dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
}

int main()
{
      ///input 2d array dp
      make2dRangeDP();
      query(1,1,N,M);


      return 0;
}
