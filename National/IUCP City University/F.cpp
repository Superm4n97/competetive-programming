#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define mod 1000000007

using namespace std;

ll n,m,k , ans = 0 , F[50];

ll amodb(ll a)
{
      return a - a/mod*mod;
}

ll bigmod(ll a, ll pw)
{
      if (pw==0)return 1;
      ll temp = bigmod(a,pw/2);
      temp = amodb(temp*temp);
      if (pw&1)temp  = amodb(temp*a);
      return temp;
}

ll solve(ll A, ll B, ll C, ll D, ll E)
{
      ll u = 1;
      for (ll i=A+1 ; i<=n ; i++) u = amodb(u*i);
      u = amodb(u*bigmod(F[B],mod-2));
      u = amodb(u*bigmod(F[C],mod-2));
      u = amodb(u*bigmod(F[D],mod-2));
      u = amodb(u*bigmod(F[E],mod-2));
      return u;
}

int main()
{
      F[0] = 1;
      for (int i=1 ; i<20 ; i++)F[i] = amodb(F[i-1]*i);
      cin >> n >> m >> k;

      for (ll C = 0 ; C*2<=m ; C++){
            ll B = m - C*2;
            for (ll E = 0 ; E*2<=k ; E++){
                  ll D = k - E*2;
                  if (B+C+D+E>n)continue;
                  ans=amodb(ans+solve(n-(B+C+D+E),B,C,D,E));
            }
      }
      cout << ans << endl;

      return 0;
}
