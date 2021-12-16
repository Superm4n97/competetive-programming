#include<bits/stdc++.h>
#define ll long long int
#define mod 998244353
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,k , dp[1005][5][2005] , ans = 0;

ll rec(ll pos, ll pre, ll rem_k)
{
      if (rem_k<0){
            return 0;
      }

      if (dp[pos][pre][rem_k] != -1)return dp[pos][pre][rem_k];

      if (pos == n+1){

            if (rem_k==0)return dp[pos][pre][rem_k] = 1;
            return dp[pos][pre][rem_k] = 0;
      }

      ll ret = 0;

      for (ll i=0 ; i<=3 ; i++){
            if (i==0){
                  if (pre==3)ret += rec(pos+1,i,rem_k-1);
                  else ret += rec(pos+1,i,rem_k);
            }
            else if (i==1){
                  if (pre==1) ret += rec(pos+1,i,rem_k);
                  else if (pre==0 || pre==3) ret += rec(pos+1,i,rem_k-1);
                  else ret += rec(pos+1,i,rem_k-2);
            }
            else if (i==2){
                  if (pre==2) ret += rec(pos+1,i,rem_k);
                  else if (pre==0 || pre==3) ret += rec(pos+1,i,rem_k-1);
                  else ret += rec(pos+1,i,rem_k-2);
            }
            else {
                  if (pre==0)ret += rec(pos+1,i,rem_k-1);
                  else ret += rec(pos+1,i,rem_k);
            }

            ret%=mod;
      }

      return dp[pos][pre][rem_k] = ret;
}

int main()
{
      cin >> n >> k;

      memset(dp,-1,sizeof dp);

      for (ll i=0 ; i<=3 ; i++){

            if (i==1 || i==2)ans += rec(2,i,k-2);
            else ans += rec(2,i,k-1);

            ans%=mod;
      }

      cout << ans << endl;


      return 0;
}
