#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 200005

using namespace std;

string s;
ll dp[maxn][3] , one[maxn][3] , zero[maxn][3] , n , x, y;

ll rec(ll pos, ll pre)
{
      if (dp[pos][pre]!=-1)return dp[pos][pre];
      if (pos == n-1){
            if (s[pos]=='?')return dp[pos][pre] = 0LL;
            ll temp = s[pos]-'0';
            if (pre==temp)return dp[pos][pre] = 0LL;

            if (pre==0 && temp==1)return dp[pos][pre] = x;
            return dp[pos][pre] = y;
      }

      ll ret = 0;

      if (s[pos]!='?'){
            ll temp = s[pos]-'0';
            if (temp==pre)ret = rec(pos+1,temp);
            else {
                  if (pre==0 && temp==1)ret = rec(pos+1,temp)+x;
                  else ret = rec(pos+1,temp)+y;
            }
      }
      else {
            ll t1 , t3, t4 , t2 , temp = 1;
            {///temp = 1;
                if (pre==0)t1 = rec(pos+1,temp)+x;
                else t1 = rec(pos+1,temp);
            }
            {///temp = 0
                  temp = 0;
                  if (pre==1)t2 = rec(pos+1,temp)+y;
                  else t2 = rec(pos+1,temp);
            }

            ret = min(t1,t2);
      }

      return dp[pos][pre] = ret;
}

int main()
{
      memset(dp,-1,sizeof dp);
      cin >> s;
      n = s.size();
      cin >> x >> y;

      if (n==1){
            cout << 0 << endl;
            return 0;
      }

      if (s[0]=='?'){
            cout << min(rec(1,0),rec(1,1)) << endl;
      }
      else {
            ll temp = s[0] - '0';
            cout << rec(1,temp) << endl;
      }

      return 0;
}
