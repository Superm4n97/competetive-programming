#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 4000006

using namespace std;

vector<ll> primes;
bool pms[maxn];
ll P[65];

void sieve()
{
      for (ll i = 2 ; i<maxn ; i++){
            if (pms[i] == false){
                  primes.push_back(i);
                  for (ll j = i*i ; j<maxn ; j+=i){
                        pms[j] = true;
                  }
            }
      }
}

ll solve(ll x, ll y, ll dif)
{
      if (dif==0)return 0LL;
      if (dif==1)return y-x;
      vector<ll> divisor;
      ll temp = dif , siz = primes.size();
      for (ll i=0 ; i<siz ; i++){
            if (primes[i]*primes[i]>temp)break;
            if (temp%primes[i]==0){
                  divisor.push_back(primes[i]);
                  while(temp%primes[i]==0){
                        temp/=primes[i];
                  }
            }
      }
      if (temp>1)divisor.push_back(temp);

      ll sz = divisor.size(), a = 0, b = 0;

      for (ll i=1 ; i<P[sz] ; i++){
            ll lcm = 1LL , px = i , cnt = 0;
            for (ll j = 0 ; j<sz ; j++){
                  if (px%2){
                        lcm*=divisor[j];
                        cnt++;
                  }
                  px/=2;
            }

            if (cnt%2){
                  a += (x/lcm);
                  b += (y/lcm);
            }
            else {
                  a -= (x/lcm);
                  b -= (y/lcm);
            }
      }

      x-=a;
      y-=b;

      return y-x;
}

int main()
{
      P[0] = 1;
      for (ll i=1 ; i<=62 ; i++)P[i] = P[i-1]*2;

      sieve();

      ll tc;
      scanf("%lld",&tc);

      for (ll _t = 1 ; _t<=tc ; _t++){
            ll a, b, m;
            scanf("%lld %lld %lld",&a,&b,&m);

            if (a>b)swap(a,b);

            ll ans = solve(a-1 , a+m , b-a);
            if (a==1 && b==1)ans = 1;
            printf("Case %lld: %lld\n",_t,ans);
      }


      return 0;
}
