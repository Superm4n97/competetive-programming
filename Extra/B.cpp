#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200006
#define mod 998244353

using namespace std;

ll dp[maxn][4] , n,k,R,S,P , ans = 0;
string s;

ll rec(ll pos, ll id)
{
      if (pos>=n)return 0;
      if (dp[pos][id]!=-1)return dp[pos][id];
      ll ret = 0;
      if (id == 0 && s[pos]=='s')ret = R;
      if (id == 1 && s[pos]=='p')ret = S;
      if (id == 2 && s[pos]=='r')ret = P;
      ll t1 = (id+1)%3 , t2 = (id+2)%3;
      ret+=max(rec(pos+k,t1),rec(pos+k,t2));
      return dp[pos][id] = ret;
}

int main()
{
      memset(dp,-1,sizeof dp);
      cin >> n >> k;
      cin >> R >> S >> P;
      cin >> s;

      for (int i=0 ; i<k ; i++){
            ans+=max(rec(i,0),max(rec(i,1),rec(i,2)));
      }
      cout << ans << endl;


      return 0;
}

/*
5
0 0 1 1 0
1 1 0 0 1

6
0 0 0 0 0 0
1 1 1 1 1 1

6
1 1 1 1 1 1
0 0 0 0 0 0

2
0 1
1 0

1
0
0
*/
