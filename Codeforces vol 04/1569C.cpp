#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define mod 998244353

using namespace std;

ll F[maxn] , INV[maxn];

ll mod_a(ll a)
{
      return a - a/mod*mod;
}

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;

      ll temp = bigmod(a,p/2);
      temp = mod_a(temp*temp);
      if (p&1)temp = mod_a(temp*a);

      return temp;
}

ll ncr(ll n, ll r)
{
      return mod_a(mod_a(F[n]*INV[n-r])*INV[r]);
}

void init()
{
      F[0] = 1;
      for (ll i=1; i<maxn ; i++)F[i] = mod_a(F[i-1]*i);

      INV[maxn-2] = bigmod(F[maxn-2],mod-2);
      for (ll i = maxn-3 ; i>=0 ; i--)INV[i] = mod_a(INV[i+1]*(i+1));
}

int main()
{
      init();

      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);

            vector<ll>v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  v.push_back(a);
            }

            sort(v.rbegin(),v.rend());

            if (v[1]==v[0])printf("%lld\n",F[n]);
            else {
                  if (v[1]+1 != v[0])printf("0\n");
                  else {
                        ll cnt = 1;
                        for (int i=2 ; i<n ; i++){
                              if (v[i]!=v[i-1])break;
                              cnt++;
                        }
                        ll sm = n-cnt-1, not_nice = 0;

                        for (ll i=0 ; i<=sm ; i++)not_nice = mod_a(not_nice+mod_a(mod_a(ncr(sm,i)*F[i])*F[n-i-1]));
                        printf("%lld\n",mod_a(F[n]-not_nice+mod));
                  }
            }
      }

      return 0;
}
