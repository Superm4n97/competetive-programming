#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 5005
#define mod 1000000007

using namespace std;

ll n,m, k, dp[maxn][maxn] , cnt[maxn] , A[maxn];

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll rec(ll pos, ll x)
{
      if (dp[pos][x]!=-1)return dp[pos][x];
      if (pos>n || pos<1)return dp[pos][x] = 0;
      if (x==0)return dp[pos][x] = 1;

      return dp[pos][x] = amod(rec(pos+1,x-1) + rec(pos-1,x-1));
}

int main()
{
      memset(dp,-1,sizeof dp);
      scanf("%I64d %I64d %I64d",&n, &k , &m);
      for (int i=1 ; i<=n ; i++)scanf("%I64d",&A[i]);

      ll sum = 0;

      for (int i=1 ; i<=n ; i++){
            for (int j=0 ; j<=k ; j++){
                  cnt[i] = amod(rec(i,j)+cnt[i]);
            }
            show(cnt[i]);

            sum = amod(sum+amod(cnt[i]*A[i]));
      }

      while(m--){
            ll id, x;
            scanf("%I64d %I64d",&id,&x);

            ll temp = amod(A[id]*cnt[id]);
            sum = amod(sum+mod-temp);
            A[id] = x;
            temp = amod(A[id]*cnt[id]);
            sum = amod(sum+temp);

            printf("%I64d\n",sum);
      }

      return 0;
}
