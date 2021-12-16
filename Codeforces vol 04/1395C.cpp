#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m, dp[204][600],A[205],B[205];

ll rec(ll pos, ll mask)
{
      if (dp[pos][mask] != -1)return dp[pos][mask];

      if (pos==n+1){
            return mask;
      }

      //ll temp = mask|(A[pos]&B[1]);
      ll temp;

      for (int i=1 ; i<=m ; i++){

            ll tut = rec(pos+1,mask|(A[pos]&B[i]));

            if (i==1)temp = tut;
            else temp = min(temp,tut);
      }

      /*show(temp);
      show(pos);
      show(mask);*/

      return dp[pos][mask] = temp;
}

int main()
{
      cin >> n >> m;

      for(int i=1; i<=n ; i++)cin >> A[i];
      for(int j=1; j<=m ; j++)cin >> B[j];

      memset(dp,-1,sizeof dp);

      cout << rec(1,0) << endl;

      return 0;
}
