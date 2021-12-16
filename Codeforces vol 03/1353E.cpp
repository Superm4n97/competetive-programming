#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll dp[maxn][3],n , csum[2*maxn] , k;
string s;

void clean()
{
      for (int i=0 ; i<=n+2 ; i++){
            dp[i][0]=dp[i][1] = -1;
            csum[i] = csum[n+i] = 0;
      }
}

ll rngSum(ll l, ll r)
{
      if (l>r)return 0;
      return csum[r] - csum[l-1];
}

ll rec(ll pos, ll stage)
{
      if (pos>n)return 0;
      if (dp[pos][stage] != -1) return dp[pos][stage];
      ll ret = maxn;
      if (stage==0){
            if (s[pos-1]=='0')ret = rec(pos+1,stage);
            else {
                  ll nxt = pos+k;
                  ret = rec(nxt,1) + rngSum(pos+1,nxt-1);
                  ret = min(ret,rec(pos+1,stage)+1);
            }
      }
      else {
            ll pre = 0 , nxt = pos+k;
            if (s[pos-1]=='0')pre = 1;
            ret = min(ret,rec(nxt,stage)+pre+rngSum(pos+1,nxt-1));
            ret = min(ret,rngSum(pos+1,n));
      }
      return dp[pos][stage] = ret;
}

int main()
{
      int  tc;
      scanf("%lld",&tc);
      while(tc--){
            scanf("%lld %lld",&n,&k);
            cin >> s;
            clean();

            for (int i=1 ; i<=n ; i++)csum[i] = csum[i-1]+(s[i-1]-'0');
            for (int i=n+1 ; i<=2*n+1 ; i++)csum[i] = csum[i-1];
            printf("%lld\n",rec(1,0));
      }

      return 0;
}
/*

1
4 2
1111
*/
