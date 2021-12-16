#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << endl
#define maxn 200050
#define mod 1000000007

using namespace std;

ll dp[maxn] , cnt[12][2] , sum;

ll amod(ll a)
{
      return a - a/mod*mod;
}

void initialation()
{
      dp[0] = cnt[0][0] = sum = 1;
      for (int i=1 ; i<maxn ; i++){
            sum = amod(sum+cnt[9][0]);
            for (int j=0 ; j<10 ; j++){
                  if (j==0)cnt[j][1] = cnt[9][0];
                  else if (j==1)cnt[j][1] = amod(cnt[0][0]+cnt[9][0]);
                  else cnt[j][1] = cnt[j-1][0];
            }
            for (int j=0 ; j<10 ; j++)cnt[j][0] = cnt[j][1];
            dp[i] = sum;
      }
}

int main()
{
      initialation();

      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n,m,ans = 0;
            scanf("%lld %lld",&n,&m);
            while(n){
                  ll d = n%10;
                  n/=10;
                  ans = amod(ans+dp[m+d]);
            }
            printf("%lld\n",ans);
      }

      return 0;
}
