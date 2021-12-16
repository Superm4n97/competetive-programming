#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define mod 1000000007
#define maxn 1005

using namespace std;

ll dp[maxn][maxn];

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll rec(ll n, ll r)
{
      if (n<r)return 0;
      if (dp[n][r] != -1)return dp[n][r];
      if (n==r)return dp[n][r] = 1;
      if (r==0)return dp[n][r] = 1;
      return dp[n][r] = amod(rec(n-1,r) + rec(n-1,r-1));
}

int main()
{
      memset(dp,-1,sizeof dp);
      ll tc;
      scl(tc);

      while(tc--){
            ll n,k;
            scl(n) , scl(k);
            vector<ll> v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);
                  v.push_back(a);
            }
            sort(v.rbegin(),v.rend());

            ll peek = v[k-1], cnt = 0 , total = 0, sum = 0;
            for (int i=0 ; i<n ; i++){
                  if (v[i]==peek){
                        total++;
                        if (i<k)cnt++;
                  }
            }
//            show(cnt);
//            show(total);

            cout << rec(total,cnt) << "\n";
      }

      return 0;
}
