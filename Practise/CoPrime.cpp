#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " " << x << endl

using namespace std;

ll A,B,n;
vector<ll> primes;

void findPrimes(ll a)
{
      for (ll i=2 ; i*i<=n ; i++){
            if (a%i==0){
                  primes.push_back(i);
                  while(a%i==0)a/=i;
            }
      }
      if (a>1)primes.push_back(a);
}

ll calculate(ll x)
{
      ll ret = 0 , bit = primes.size();
      ll range = 1;
      for (ll i = 1 ; i<=bit ; i++)range*=2;

      for (ll i = 1 ; i<range ; i++){
            ll a = i , lcm = 1 , cnt = 0;
            for (ll j = 0 ; j<bit ; j++){
                  if (a%2){
                        cnt++;
                        lcm = lcm*primes[j];
                  }
                  a/=2;
            }
            ll num = x/lcm;
            if (cnt%2)ret+=num;
            else ret-=num;
      }
      return x-ret;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){

            scanf("%lld %lld %lld",&A,&B,&n);

            findPrimes(n);
            printf("Case #%d: %lld\n",_t,calculate(B)-calculate(A-1));

            primes.clear();
      }

      return 0;
}
