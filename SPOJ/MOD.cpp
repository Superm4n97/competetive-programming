#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll amodb(ll a, ll b){return a - (a/b*b);}

ll bigmod(ll a, ll pw, ll mod)
{
      if (pw==0)return 1;
      ll temp = bigmod(a,pw/2,mod);
      temp = amodb(temp*temp,mod);
      if (pw - pw/2*2)temp = amodb(temp*a,mod);
      return temp;
}

ll BSGS(ll a, ll x, ll m)///a^m = x mod m
{
      a = amodb(a,m), x = amodb(x,m);
      ll add = 0, k = 1, gcd;
      while((gcd = __gcd(a,m))>1){///2^x = 8%16
            if (x==k)return add+1;
            if (amodb(x,gcd))return -1;
            x/=gcd, m/=gcd , add++;
            k = amodb(k*(a/gcd),m);
      }

      ll n = sqrt(m)+1;

      show(k);
      show(n);
      show(add);

      unordered_map<ll,ll> mp;
      ll powA[n+4];///power of a
      powA[0] = 1;
      for (int i=1 ; i<n+3 ; i++)powA[i] = amodb(powA[i-1]*a, m);

      for (ll q = 0 ; q<n ; q++){
            ll temp = amodb(powA[q]*x , m);
            mp[temp] = q+1;
      }

      ll temp = 1;

      for (ll p = 1 ; p<=n ; p++){
            //ll temp = amodb(bigmod(a,n*p,m)*k,m);
            temp = amodb(amodb(powA[n]*temp,m)*k,m);
            if(mp[temp]){
                  ll q = mp[temp]-1;
                  return n*p-q+add;
            }
      }
      return -1;
}

int main()
{
      ll x,z,k;
      while(true){
            scanf("%lld %lld %lld",&x,&z,&k);
            if (x==0 && z==0 && k==0)break;
            ll ans = BSGS(x,k,z);
            if (ans==-1)printf("No Solution\n");
            else printf("%lld\n",ans);
      }

      return 0;
}

      /**
      a^m = x % m
      a/gcd * a^m-1 = x/gcd % m/gcd
      k*a^m-1 = x%m
      k * a^np = x*a^q % m
      **/
