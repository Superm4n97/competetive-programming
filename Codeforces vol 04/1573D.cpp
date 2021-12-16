#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[3005][3005], A[3005],n;

ll rec(ll x, ll y)
{
      if (dp[x][y] != -1)return dp[x][y];
      if (x==y || x>y)return dp[x][y] = 0;

      ll t = 10000000000000016, t2, t3;
      t2 = t3 = t;
      if (A[x]==A[x+1])t2 = rec(x+1,y);
      if (A[y]==A[y-1])t3 = rec(x,y-1);
      if (A[x]==A[y])  t  = rec(x+1,y-1)+1;

      t = min(t,min(t2,t3));

      return dp[x][y] = min(min(rec(x,y-1)+1,rec(x+1,y))+1,t);
}

void clean()
{
      for (int i=0 ; i<n+3 ; i++){
            for (int j=0 ; j<n+4 ; j++)dp[i][j] = -1;
      }
}

int main()
{
      ll tc;
      scanf("%lld",&tc);
      while(tc--){
            scanf("%lld",&n);
            clean();
            for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);
            printf("%lld\n",rec(1,n));
      }

      return 0;
}
#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[3005][3005], A[3005],n;

ll rec(ll x, ll y)
{
      if (dp[x][y] != -1)return dp[x][y];
      if (x==y || x>y)return dp[x][y] = 0;

      ll t = 10000000000000016, t2, t3;
      t2 = t3 = t;
      if (A[x]==A[x+1])t2 = rec(x+1,y);
      if (A[y]==A[y-1])t3 = rec(x,y-1);
      if (A[x]==A[y])  t  = rec(x+1,y-1)+1;

      t = min(t,min(t2,t3));

      return dp[x][y] = min(min(rec(x,y-1)+1,rec(x+1,y))+1,t);
}

void clean()
{
      for (int i=0 ; i<n+3 ; i++){
            for (int j=0 ; j<n+4 ; j++)dp[i][j] = -1;
      }
}

int main()
{
      ll tc;
      scanf("%lld",&tc);
      while(tc--){
            scanf("%lld",&n);
            clean();
            for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);
            printf("%lld\n",rec(1,n));
      }

      return 0;
}
