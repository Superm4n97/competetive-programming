#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005
#define inf 100000000000000017

using namespace std;

ll dp[maxn][maxn] , A[maxn] , B[maxn] , n, m;

ll rec(ll x, ll y)
{
      if (dp[x][y] != -1)return dp[x][y];
      if (x>n || y>m){
            ll temp =0;
            if (x<=n)temp = n-x+1;
            if (y<=m)temp = m-y+1;
            return dp[x][y] = temp;
      }

      ll t1 = inf , t2 = inf , t3 = inf;
      t1 = rec(x+1,y)+1;
      t2 = rec(x,y+1)+1;
      t3 = rec(x+1,y+1)+1;
      if (A[x]==B[y])t3--;

      return dp[x][y] = min(min(t1,t2),t3);
}

int main()
{
      memset(dp,-1,sizeof dp);
      cin >> n >> m;
      for (int i=1 ; i<=n ; i++)cin >> A[i];
      for (int i=1 ; i<=m ; i++)cin >> B[i];

      cout << rec(1,1) << endl;

      return 0;
}
