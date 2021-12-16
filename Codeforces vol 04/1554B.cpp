#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%lld",&w)
#define show(x)         cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n,m;
            scl(n);
            scl(m);

            if (m<n){
                  printf("0\n");
                  continue;
            }

            ll res = 0;

            for (ll b = 33 ; b>=0 ; b--){
                  if (((1LL<<b)&n) == 0){
                        if (b<=3){
                             show(res);
                             show((res+(1LL<<b)));
                             show(((res+(1LL<<b))^n));
                        }
                        if ((((res+(1LL<<b)))^n) <= m+1){
                              res+=(1LL<<b);
                        }
                  }
            }

            printf("%lld\n",res);
      }

      return 0;
}
