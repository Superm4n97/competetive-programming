#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[1005], isPalin[1005][1005] , n;
string s;

ll palindrome(ll x, ll y)
{
      if (isPalin[x][y] != -1)return isPalin[x][y];
      if (x==y)return isPalin[x][y] = 1;
      if (x+1==y){
            if (s[x]==s[y])return isPalin[x][y] = 1;
            else return isPalin[x][y] = 0;
      }

      if (s[x]==s[y] && palindrome(x+1,y-1))return isPalin[x][y] = 1;
      else return isPalin[x][y] = 0;
}

ll rec(ll pos)
{
      if (dp[pos] != -1) return dp[pos];
      if (pos==n)return dp[pos] = 0;

      ll ret = rec(pos+1)+1;
      for (ll i=pos+1 ; i<n ; i++){
            ll rest = rec(i+1);
            if (palindrome(pos,i))rest++;
            else rest+=(i-pos+1);
            ret = min(ret,rest);
      }
      return dp[pos] = ret;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            cin >> s;
            n = s.size();

            memset(dp,-1,sizeof dp);
            memset(isPalin,-1,sizeof isPalin);

            printf("Case %d: %lld\n",_t,rec(0));
      }

      return 0;
}
/*
3
AAAA
ABCDEFGH
QWERTYTREWQWERT
*/
