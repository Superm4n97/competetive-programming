#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 505
#define inf 100000000000014

using namespace std;

ll dp[maxn][maxn][3][3];

ll rec(ll x, ll y, ll key, ll alter)
{
      if (dp[x][y][key][alter] != -inf)return dp[x][y][key][alter];
      if (x==0 && y==0 && alter==1)return 0;

      ll ret = -inf;
      if (x)ret = max(ret,-rec(x-1,y,0,alter)-1);
      if (y)ret = max(ret,-rec(x+1,y-1,0,alter)-1);
      if (x && key==0) ret = max(ret,-rec(x,y,1,alter));
      if (alter==0)ret = max(ret,-rec(x,y,0,1)-1);

      return dp[x][y][key][alter] = ret;
}

int main()
{
      for (int i=0 ; i<maxn ; i++){
            for (int j=0 ; j<maxn ; j++){
                  for (int k=0 ;k<3 ; k++){
                        dp[i][j][k][0]=dp[i][j][k][1] = -inf;
                  }
            }
      }

      int tc;
      cin >> tc;

      while(tc--){
            ll n , _01=0,_00=0,_0_ = 1;
            cin >> n;
            string s;
            cin >> s;

            for (int i=0,j=n-1 ; i<=j ; i++,j--){
                  if (i==j){
                        if (s[i]=='0')_0_ = 0;
                  }
                  else {
                        if (s[i] != s[j])_01++;
                        else if (s[i]=='0')_00++;
                  }
            }
            ll ans = rec(_01,_00,0,_0_);
            if (ans<0)cout << "BOB\n";
            else if (ans>0)cout << "ALICE\n";
            else cout << "DRAW\n";
      }


      return 0;
}
