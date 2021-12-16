#include <bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define mod 1000000007
#define show(x) cout << #x << " : " << x << endl

using namespace std;


int main()
{
      ll tc;
      scanf("%lld",&tc);

      while(tc--){
            ll n , ans = 0;
            scanf("%lld",&n);
            ll A[n+5] , lm = 0;
            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  lm+=A[i];
            }

            for (int i=1 ; i<=n ; i++){
                  ll lcm = A[i] , sum = 0;
                  for (int j=i ; j<=n ; j++){
                        ll g = __gcd(A[j],lcm);
                        lcm = (A[j]/g)*lcm;
                        if (lcm>lm)break;
                        sum+=A[j];

                        if (sum%lcm==0)ans++;
                  }
            }
            printf("%lld\n",ans);
      }
}
