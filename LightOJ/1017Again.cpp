#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n, w, k, dp[105][105];
vector < ll> v;

ll rec(ll pos, ll rem_k)
{
      if (pos>=n)return 0;
      if (dp[pos][rem_k] != -1)return dp[pos][rem_k];
      if (rem_k==0)return dp[pos][rem_k] = 0;

      ll nxt = pos+1 , cnt = 1;

      while(nxt<n && v[pos]+w>=v[nxt]){
            cnt++;
            nxt++;
      }

      ll t1 = rec(nxt , rem_k-1)+cnt , t2 = rec(pos+1,rem_k);

      return dp[pos][rem_k] = max(t1,t2);
}

int main()
{
      int tc;
      cin >> tc;

      for (int _t=1; _t<=tc; _t++){

            v.clear();
            memset(dp,-1,sizeof dp);
            cin >> n >> w >> k;

            for (int i=0 ; i<n ; i++){
                  ll a , b;
                  cin >> a >> b;
                  v.push_back(b);
            }

            sort(v.begin() , v.end());

            cout << "Case " << _t << ": " << rec(0,k) << endl;
      }


      return 0;
}
