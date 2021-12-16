#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005
#define inf 10000000010
#define pll pair<ll,ll>

using namespace std;

ll dp[maxn][maxn][3];

//        01   00
ll rec(ll x, ll y, ll key)
{
      if (dp[x][y][key] != -inf)return dp[x][y][key];
      if (x==0 && y==0) return dp[x][y][key] = 0;
      ll ret = -inf , a;

//      show(x);
//      show(y);
//      cout << endl;

      if (x){
            a = rec(x-1,y,0);
            ret = max(ret,-a-1);
      }
      if (x && key==0){
            ret = max(ret,-rec(x,y,1));
      }
      if (y){
            ret = max(ret,-rec(x+1,y-1,0)-1);
      }
      return dp[x][y][key] = ret;
}

int main()
{
      for (int i=0 ; i<maxn ; i++){
            for (int j=0 ; j<maxn ; j++){
                  dp[i][j][0] = dp[i][j][1] = -inf;
            }
      }

//      while(true){
//            ll a,b;
//            cin >> a >> b;
//            show(rec(a,b,0));
//      }

      ll tc;
      cin >> tc;
      while(tc--){
            string s;
            ll n;
            cin >> n;
            cin >> s;

            ll _01 = 0 , _00 = 0;
            for (int i=0 , j = n-1 ; i<j ; i++,j--){
                  if (s[i] != s[j])_01++;
                  if (s[i]==s[j] && s[i]=='0')_00++;
            }

            ll ans = rec(_01,_00,0);
            if (n%2 && s[n/2]=='0')ans = -ans;

            if (ans==0) cout << "DRAW\n";
            else if (ans>0) cout << "ALICE\n";
            else cout << "BOB\n";
      }


      return 0;
}
