#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s , t;
ll n,k , dp[205][205][205];

ll rec(ll pos, ll pre, ll rem_k)
{
      if (dp[pos][pre][rem_k] != -1)return dp[pos][pre][rem_k];

      if (pos==n-1){

            if (s[pos]==t[1] || rem_k)return dp[pos][pre][rem_k] = pre;
            else return dp[pos][pre][rem_k] = 0;
      }

      ll t1 = 0 , t2 = 0 , t3 = 0;

      {//if current character is changed to first one
            if (s[pos]==t[0]) t1 = rec(pos+1 , pre+1 , rem_k);
            else if (rem_k) t1 = rec(pos+1 , pre+1 , rem_k-1);
      }
      {//if current character is changed to second one
            if (s[pos]==t[1])t2 = rec(pos+1,pre,rem_k) + pre;
            else if (rem_k) t2 = rec(pos+1,pre,rem_k-1) + pre;
      }
      {// leave as it is
            t3 = rec(pos+1,pre,rem_k);
      }

      return dp[pos][pre][rem_k] = max(t1,max(t2,t3));
}

int main()
{
      memset(dp,-1,sizeof dp);

      cin >> n >> k;
      cin >> s >> t;

      if (t[0] == t[1]){
            ll cnt = 0;
            for (int i=0 ; i<n ; i++){
                  if (s[i]==t[0])cnt++;
            }

            ll temp = cnt + min(n-cnt , k);
            temp = temp*(temp-1)/2;

            cout << temp << endl;
      }
      else cout << rec(0,0,k) << endl;

      return 0;
}
/**

(pos , pre, rem_k)


7 4
abacaba
aa

6+5+4+3+2+1
**/
