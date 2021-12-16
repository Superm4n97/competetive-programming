#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 1000006

using namespace std;

ll n,dp[105][4];
string s;

ll fndtype(char ch)
{
      if (ch=='B')return 0;
      else if (ch=='R')return 1;
      else return 2;
}

ll rec(ll pos, ll type)
{
      if (dp[pos][type] != -1)return dp[pos][type];
      if (pos==n)return 0;

      ll t = fndtype(s[pos]);
      if (t==1 || t==0){
            if (t!=type)return dp[pos][type] = inf;
            return dp[pos][type] = min(rec(pos+1,1-type),rec(pos+1,type)+1);
      }
      else {
            return dp[pos][type] = min(rec(pos+1,1-type),rec(pos+1,type)+1);
      }
}

void pathPrint(ll pos, ll type)
{
      if (pos==n)return;

      if (type==0)cout << 'B';
      else cout << 'R';

      if (dp[pos+1][1-type]<=dp[pos+1][type])pathPrint(pos+1,1-type);
      else pathPrint(pos+1,type);
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            cin >> s;

            memset(dp,-1,sizeof dp);

            ll ans = min(rec(0,0),rec(0,1)) , t = 0;
            if (rec(0,1)<rec(0,0))t = 1;
            pathPrint(0,t);
            cout << endl;
      }

      return 0;
}
/*
BRBR**RBRBR
*/
