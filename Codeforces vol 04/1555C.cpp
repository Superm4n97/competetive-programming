#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define inf 100000000000000017

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            cin >> n;

            ll A[3][n+5] , csum[3][n+5];
            memset(csum,0,sizeof csum);

            for (int i=0 ; i<2 ; i++){
                  for (int j=1 ; j<=n ; j++)scl(A[i][j]);
            }

            for (int i=1 ; i<=n ; i++){
                  csum[1][i] = csum[1][i-1]+A[1][i];
            }
            for (int i=n ; i>=1 ; i--){
                  csum[0][i] = csum[0][i+1]+A[0][i];
            }

            ll ans  = inf;

            for (int i=1 ; i<=n ; i++){
                  ans = min(ans,max(csum[0][i+1],csum[1][i-1]));
            }

            printf("%lld\n",ans);
      }

      return 0;
}
