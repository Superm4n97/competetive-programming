#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,k , A[30] , lim = 1 , ans = 0;

void INEX()
{
      for (ll i=1 ; i<lim ; i++){
            ll temp  = i, lcm = 1 , cnt = 0;
            for (ll j = 0 ; j<k ; j++){
                  if (temp&1){
                        ll g = __gcd(lcm,A[j]);
                        lcm = lcm*A[j]/g;
                        cnt++;
                  }
                  temp/=2;
            }
            if (cnt&1)ans += (n/lcm);
            else ans -= (n/lcm);
      }
}

int main()
{
      scanf("%lld %lld",&n,&k);
      for (int i=0 ; i<k ; i++)scanf("%lld",&A[i]);

      for (int i=0 ; i<k ;i++)lim*=2;

      INEX();

      printf("%lld\n",n-ans);

      return 0;
}
