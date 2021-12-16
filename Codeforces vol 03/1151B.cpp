#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[505][1050], A[505][505] , found[505];
ll n,m;
vector < ll > ans;

ll rec(ll x, ll md)
{
//      show(x);
//      show(md);
//      cout << endl;

      if (dp[x][md] != -1)return dp[x][md];

      if (x==n){
            if (md==0)return dp[x][md] = md;

            found[x] = 1;
            //ans.push_back(y);
            return dp[x][md] = md;
      }
      ll ret = 0;

      for (int j = 1 ; j<=m ; j++){
            ll temp = md^A[x+1][j];
            ret = max(ret , rec(x+1,temp));
            if (found[x+1]==1){
                  found[x] = 1;
//                  show(x);
//                  show(j);
                  ans.push_back(j);
                  break;
            }
      }
      return dp[x][md] = ret;
}

int main()
{
      /*
      scanf("%I64d %I64d",&n,&m);
      for (int i=1 ; i<=n ; i++){
            for (int j = 1 ; j<=m ; j++)scanf("%I64d",&A[i][j]);
      }
      */

      cin >> n >> m;
      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++)cin >> A[i][j];
      }

      memset(dp,-1,sizeof dp);

      ll ret = 0;
      //show(ret);

      for (ll i=1 ; i<=m ; i++){
            ret = max(ret , rec(1,A[1][i]));

            if (found[1]==1){
                  ans.push_back(i);
                  break;
            }
      }


      if (ret==0)cout << "NIE" << endl;
      else {
            cout << "TAK" << endl;
            for (int i=ans.size()-1 ; i>=0 ; i--)cout << ans[i] << " ";
            cout << endl;
      }



      return 0;
}
