#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 105

using namespace std;

ll n, A[maxn], dp[maxn][maxn];

ll rec(ll x, ll y)
{
      if (dp[x][y] != -1)return dp[x][y];
      if (x==y)return dp[x][y] = 1;
      if (x>y)return dp[x][y] = 0;

      ll ret = rec(x+1,y)+1;
      if (A[x] == A[y])ret = min(ret,rec(x+1,y-1)+1);

      for (int i=x+1 ; i<y ; i++){
            if (A[i]==A[x])ret = min(ret,rec(x+1,i-1) + rec(i,y));
      }
//      show(x);
//      show(y);
//      show(ret);
//      cout << endl;

      return dp[x][y] = ret;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1; _t<=tc ; _t++){
            scanf("%lld",&n);
            memset(dp,-1,sizeof dp);
            for (int i=1; i<=n ; i++)scanf("%lld",&A[i]);
            printf("Case %d: %lld\n",_t,rec(1,n));
      }

      return 0;
}
