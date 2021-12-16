#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[52][52][52] , n[4];
string s[4];

ll rec(ll a, ll b, ll c)
{
      if (a==n[0] || b==n[1] || c==n[2])return 0;
      if (dp[a][b][c] != -1)return dp[a][b][c];

      if (s[0][a]==s[1][b] && s[0][a]==s[2][c])return dp[a][b][c] = rec(a+1,b+1,c+1)+1;
      else{
            ll t1 = rec(a+1,b,c) , t2 = rec(a,b+1,c), t3 = rec(a,b,c+1);
            return dp[a][b][c] = max(t1,max(t2,t3));
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            cin >> s[0] >> s[1] >> s[2];
            n[0] = s[0].size();
            n[1] = s[1].size();
            n[2] = s[2].size();

            memset(dp,-1,sizeof dp);

            printf("Case %d: %lld\n",_t,rec(0,0,0));
      }

      return 0;
}
