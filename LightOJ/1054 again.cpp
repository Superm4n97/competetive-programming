#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

vector<ll> primes;
ll cnt[1000006];

ll amodb(ll a, ll b)
{
      return a - a/b*b;
}


void sieve(ll n)
{

      for (ll i=2 ; i<=n ; i++){
            if (cnt[i]==0){
                  primes.push_back(i);
                  for (ll j = i*i; j<=n ; j+=i)cnt[j] = 1;
            }
      }
      return;
}

ll bigmod(ll a, ll pw)
{
      if (pw==0)return 1;
      if (pw&1LL)return amodb(a*bigmod(a,pw-1),mod);
      else {
            ll temp = bigmod(a,pw/2);
            return amodb(temp*temp,mod);
      }
}

ll SOD(ll p, ll a)
{
      ll temp = amodb(bigmod(p,a+1)-1+mod,mod);
      return amodb(temp*bigmod(p-1,mod-2),mod);
}

ll solve(ll n, ll m)
{
      ll ret = 1;
      for (ll i=0 ; i<primes.size() ; i++){
            if (primes[i]*primes[i]>n)break;
            if (n%primes[i]==0){
                  ll pw = 0;
                  while(n%primes[i]==0){
                        pw++;
                        n/=primes[i];
                  }
                  pw*=m;

                  ret = amodb(ret*SOD(primes[i],pw),mod);
            }
      }
      if (n>1){
            ret = amodb(ret*SOD(n,m),mod);
      }
      return ret;
}

int main()
{
      sieve(1000003);

      int tc;
      scanf("%d",&tc);

      for (int _t = 1; _t<=tc ; _t++){
            ll n , m;
            scanf("%lld %lld",&n,&m);

            printf("Case %d: ",_t);

            if (m==0 || n==1){
                  printf("1\n");
                  continue;
            }
            printf("%lld\n",solve(n,m));
      }

      return 0;
}
