#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x " : " << x << endl
#define inf 10000000000000016
#define maxn 2003
#define mod 1000000007

using namespace std;

ll n,e,k , dp[maxn][maxn] , mp[maxn][maxn] , P[15];

ll amodb(ll a)
{
      return a - a/mod*mod;
}

ll rec(ll pos, ll mask)
{
      if (dp[pos][mask] != -1)return dp[pos][mask];
      if (pos==n){
            return dp[pos][mask] = 1;
      }

      ll temp = mask,new_mask = (mask*2)%P[2*e+1];
      ll nxt = pos+1;

      for (int i=-e,j=2*e ; i<=e ; i++,j--){
            if (nxt+i>=n || nxt+i<0){
                  new_mask = (new_mask|P[j])%P[2*e+1];
            }
      }

      ll ret = 0;

      for (int i=-e,j=2*e ; i<=e; i++,j--){
            if ((mask&P[j])==0){
                  if (mp[pos][pos+i]==0){
                        ret = amodb(ret+rec(pos+1,(new_mask|P[j+1])%P[2*e+1]));
                  }
            }
      }

      return dp[pos][mask] = ret;
}

int main()
{
      scanf("%lld %lld %lld",&n,&e,&k);
      for (int i=0 ; i<k ; i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            mp[a-1][b-1] = 1;
      }

      memset(dp,-1,sizeof dp);
      P[0] = 1;
      for (int i=1; i<=10 ; i++)P[i] = P[i-1]*2;
      ll mask = 0;
      for (int i=-e,j=2*e ; i<=e ; i++,j--){
            if (i<0 || i>=n){
                  mask = (mask|P[j]);
            }
      }

      ll ans = rec(0,mask);

      printf("%lld\n",ans);


      return 0;
}
