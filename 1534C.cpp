#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;
      ll temp = bigmod(a,p/2);
      temp = (temp*temp)%mod;
      if (p%2==1)temp = (temp*a)%mod;
      return temp;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);
            ll A[n+5] , id[n+5] , vis[n+5] , B[n+5] , cnt = 0;
            memset(vis,0,sizeof vis);

            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  id[A[i]] = i;
            }
            for (int i=1 ; i<=n ; i++)scanf("%lld",&B[i]);

            for (int i=1 ; i<=n ; i++){
                  if (vis[i]==0){
                        cnt++;
                        ll a = i;
                        while(true){
                              vis[a] = 1;
                              a = id[B[a]];
                              if (vis[a]==1)break;
                        }
                  }
            }
            printf("%lld\n",bigmod(2,cnt));
      }


      return 0;
}
