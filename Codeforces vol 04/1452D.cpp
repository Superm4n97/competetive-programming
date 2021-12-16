#include<bits/stdc++.h>
#define ll long long int
#define maxn 1000006
#define mod 998244353

using namespace std;

ll Normal(ll a)
{
      ll temp = a / mod;
      temp *= mod;

      a -= temp;

      if (a<0)a += mod;

      return a;
}

ll Summation(ll a, ll b)
{
      a += b;
      if (a >= mod)a -= mod;
      return a;
}

ll Substraction(ll a, ll b)
{
      a -= b;
      if(a<0)a += mod;
      return a;
}

ll Multiplication(ll a, ll b)
{
      a *= b;
      ll temp = a/mod;
      temp *= mod;

      return a - temp;
}

ll bigMod(ll a, ll p)
{
      if (p==0)return 1;
      if (p==1)return a % mod;

      ll temp = bigMod(a,p/2);

      temp = Multiplication(temp,temp);

      if (p%2)temp = Multiplication(temp,a);

      return temp;
}

ll modInverse(ll a)
{
      return bigMod(a,mod-2);
}

ll n,F[maxn] , P[maxn];

int main()
{
      cin >> n;

      F[0] = 0;
      F[1] = 1;
      P[0] = 1;
      P[1] = 2;

      for (int i=2 ; i<=n+2 ; i++){
            P[i] = (P[i-1]*2)%mod;
            F[i] = (F[i-1]+F[i-2])%mod;
      }

      ll ans = (F[n]* modInverse(P[n]))%mod;

      cout << ans << endl;

      return 0;
}

