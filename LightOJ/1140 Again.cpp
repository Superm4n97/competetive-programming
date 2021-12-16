#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s;
ll n , dp[15][3][3] , P[15];

ll remaining(ll pos)
{
      ll ret = 0;
      for (int i=pos ; i<n ; i++)ret = ret*10+(s[i]-'0');
      return ret;
}

ll rec(ll pos, ll previousNonZero , ll isLessThan)
{
      if (dp[pos][previousNonZero][isLessThan] != -1)return dp[pos][previousNonZero][isLessThan];
      if (pos==n)return dp[pos][previousNonZero][isLessThan] = 0;
/*0 - 1 - 2,0,0 - */
      if (previousNonZero==0){
            ll ret = rec(pos+1,previousNonZero,1);
            for (char i = '1' ; i<=s[pos] ; i++){
                  if (i<s[pos])ret+=rec(pos+1,1,1);
                  else ret += rec(pos+1,1,0);
            }
            return dp[pos][previousNonZero][isLessThan] = ret;
      }
      if (isLessThan==0){
            ll ret = 0;
            if (s[pos]=='0')ret = remaining(pos+1);
            else ret = P[n-pos-1];
            for (char i = '1';  i<=s[pos] ; i++){
                  if (i==s[pos])ret+=rec(pos+1,previousNonZero,0);
                  else ret+=rec(pos+1,previousNonZero,1);
            }
            return dp[pos][previousNonZero][isLessThan] = ret;
      }
      else {
            ll ret = P[n-pos-1];
            for (int i='1' ; i<='9' ; i++)ret+=rec(pos+1,previousNonZero,isLessThan);
            return dp[pos][previousNonZero][isLessThan] = ret;
      }
}

void initialize()
{
      memset(dp,-1,sizeof dp);
}

void convert(ll a)
{
      s = "";
      while(a){
            ll rem = a%10;
            s.push_back('0'+rem);
            a/=10;
      }
      reverse(s.begin(),s.end());
      n = s.size();
      return;
}

int main()
{
      P[0] = 1;
      P[1] = 10;
      for (int i=2 ; i<15 ; i++)P[i] = P[i-1]*10;
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll a,b;
            scanf("%lld %lld",&a,&b);

            initialize();
            convert(b);
            b = rec(0,0,0);

            show(s);

            initialize();
            convert(a-1);
            a = rec(0,0,0);

            show(a);
            show(b);

            printf("Case %d: %lld\n",_t,b-a);
      }

      return 0;
}
