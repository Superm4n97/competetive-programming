#include<bits/stdc++.h>
#define ll long long int
#define maxn 5205
#define show(x) cout << #x << " : "  << x << endl

using namespace std;

ll dp[maxn][maxn],n;
// A[maxn][maxn] , n;

ll findValue(char ch)
{
      if (ch>='0' && ch<='9')return (ll) ch-'0';
      return (ll) ch-'A'+10;
}

void make2dRangeDP()
{
      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=n ; j++){
                  dp[i][j] += dp[i][j-1];
            }
      }
      for (int j=1 ; j<=n ; j++){
            for (int i=1 ; i<=n ; i++){
                  dp[i][j]+=dp[i-1][j];
            }
      }
}

ll query(ll x1, ll y1, ll x2, ll y2)
{
      return dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
}

int main()
{
      cin >> n;
      for (int i=1 ; i<=n ; i++){
            string s;
            cin >> s;

            for (int j = 1  ; j<=s.size() ; j++){
                  ll temp = findValue(s[j-1]);

                  for (int k = 0 ; k<4 ; k++){

                        ll md = temp%2;
                        temp/=2;
                        //A[i][j*4-k] = md;
                        dp[i][j*4-k] = md;
                  }
            }
      }

      make2dRangeDP();

      /*
      for (int i=1 ; i<=n ; i++){
            for (int j = 1 ; j<=n ; j++)cout << A[i][j] << " ";
            cout << endl;
      }
      cout << endl;
      for (int i=1 ; i<=n ; i++){
            for (int j = 1 ; j<=n ; j++)cout << dp[i][j] << " ";
            cout << endl;
      }
      */

      vector < ll > divisor;

      for (int i=1 ; i*i<=n ; i++){
            if(n%i==0){
                  divisor.push_back(i);
                  divisor.push_back(n/i);
            }
      }

      sort(divisor.rbegin(),divisor.rend());

      ll ans = -1;

      for (int k=0 ; k<divisor.size()-1 ; k++){
            ll x = divisor[k];
            bool sol = true;

            for (int i=x ; i<=n ; i+=x){
                  for (int j = x ; j<=n ; j+=x){
                        ll temp = query(i-x+1 , j-x+1 , i, j);
                        if (temp!=0 && temp!=x*x)sol = false;
                  }
            }
            if (sol){
                  ans = x;
                  break;
            }
      }
      if (ans==-1)ans = 1;

      cout << ans << endl;


      return 0;
}
