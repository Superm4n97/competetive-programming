#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(w) scanf("%I64d",&w)
#define mod 1000000007

using namespace std;

ll dp[200005][105] , ans = 0;

ll amodb(ll a)
{
      ll temp = a/mod;
      return a - temp*mod;
}

ll rec(ll n, ll r)
{
      if (dp[n][r]!=-1)return dp[n][r];
      if (r>n)return dp[n][r] = 0;
      if (r==1)return dp[n][r] = n;
      if (r==n || r==0)return dp[n][r] = 1LL;

      return dp[n][r] = amodb(rec(n-1,r)+rec(n-1,r-1));
}

int main()
{
      memset(dp,-1,sizeof dp);
      ll tc;
      scl(tc);
      while(tc--){
            ll n , m,k;
            scl(n);
            scl(m);
            scl(k);

            ll A[n+105] , cnt[n+105];
            memset(A,0,sizeof A);
            memset(cnt,0,sizeof cnt);

            for (int i=1 ; i<=n ; i++){
                  ll a;
                  scl(a);
                  A[a]++;
            }

            for (int i=1 ; i<=n+5 ; i++)cnt[i] = cnt[i-1]+A[i];

            ans = 0;

            for (ll i=1 ; i<=n ; i++){

                  if (A[i]){
                        ll r = i+k;
                        if (r>n+5)r = n+3;
                        ll rest = cnt[r]-cnt[i] , have = A[i];

                        for (ll j=1 ; j<=m ; j++){
                              ans += amodb(rec(have,j)*rec(rest,m-j));
                              ans = amodb(ans);
                        }
                  }
            }
            printf("%I64d\n",ans);
      }

      return 0;
}
