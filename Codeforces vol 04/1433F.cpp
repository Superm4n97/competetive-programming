#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 1000000000012

using namespace std;

ll n , m , k, dp[72][72][72][72] , A[72][72] , limit;

ll rec(ll x, ll y, ll cnt, ll mod)
{

      if (dp[x][y][cnt][mod] != -1)return dp[x][y][cnt][mod];

      if (x>n){
            if (mod==0)return 0;
            else return -2;
      }

      ll t1 = -2 , t2 = -2;
      {
            if (y==m)t1 = rec(x+1,1,0,mod);
            else t1 = rec(x,y+1,cnt,mod);
      }
      {
            ll md = (mod+A[x][y]) % k;
            if(cnt<limit){
                  if (y<m)t2 = rec(x,y+1,cnt+1,md);
                  else t2 = rec(x+1,1,0,md);
            }
            if (t2 != -2)t2 += A[x][y];
      }

      return dp[x][y][cnt][mod] = max(t1,t2);
}

int main()
{
//      for (int i = 0 ; i<=71 ; i++)
//            for (int j=0 ; j<=71 ; j++)
//                  for (int k=0 ; k<=71 ; k++)
//                        for (int l=0 ; l<=71 ; l++)dp[i][j][k][l] = -inf;
      memset(dp,-1,sizeof dp);

      cin >> n >> m >> k;
      for (int i=1;i<=n; i++){
            for (int j=1 ; j<=m ; j++)cin>>A[i][j];
      }
      limit = m/2;

      ll ans = rec(1,1,0,0);

      if (ans==-2)ans = 0;

      cout << ans << endl;

      return 0;
}
