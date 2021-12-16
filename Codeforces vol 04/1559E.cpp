#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 998244353
#define maxn 100005

using namespace std;

ll n,m,M[maxn] , l[55] , r[55] , x[55] , y[55] , dp[55][maxn], pf[55][maxn];

void mobious()
{
      M[1] = 1;
      for (int i=1 ; i<maxn ; i++){
            if (M[i]==0)continue;
            for (int j=i+i ; j<maxn ; j+=i){
                  M[j] -= M[i];
            }
      }
}

ll solve(ll d)
{
      for (int i=0 ; i<n ; i++){
            x[i] = (l[i]+d-1)/d;
            y[i] = r[i]/d;
            if (x[i]>y[i])return 0;
      }

      ll new_m = m/d;

      for (int i=0 ; i<n;  i++){
            for (int j=0 ; j<=new_m ; j++){

                  if (i==0){
                        if (j>=x[i] && j<=y[i])dp[i][j] = 1;
                        else dp[i][j] = 0;
                  }
                  else {
                        ll temp = 0;
                        if (j-x[i]>=0)temp = pf[i-1][j-x[i]];
                        if (j-y[i]-1>=0)temp = (temp-pf[i-1][j-y[i]-1]+mod)%mod;
                        dp[i][j] = temp;
                  }
            }
            pf[i][0] = dp[i][0];
            for (int j=1 ; j<=new_m ; j++)pf[i][j] = (pf[i][j-1] + dp[i][j])%mod;
      }
      return pf[n-1][new_m];
}

int main()
{
      mobious();

      scanf("%lld %lld",&n,&m);
      for (int i=0 ; i<n ; i++)scanf("%lld %lld",&l[i],&r[i]);

      ll ans = 0;

      for (int i=1 ; i<=m ; i++){
            ans = (ans+mod+M[i]*solve(i))%mod;
      }
      printf("%lld\n",ans);
}
