#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10000007

using namespace std;

bool isPrime[maxn];
vector<ll> primes;

void linearSieve()
{
      for (ll i=2 ; i<maxn ; i++){
            if (isPrime[i]==false)primes.push_back(i);
            for (ll j=0 ; j<primes.size() && i*primes[j]<maxn ; j++){
                  isPrime[i*primes[j]] = true;
                  if (i%primes[j]==0)break;
            }
      }
}

ll bs(ll val)
{
      ll b = 0 , e = primes.size()-1 , ret = -1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (primes[mid]<=val){
                  ret = max(ret,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return ret;
}

int main()
{
      linearSieve();

      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);
            printf("%lld\n",bs(n)-bs(n/2));
      }

      return 0;
}
