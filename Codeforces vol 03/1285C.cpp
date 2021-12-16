#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A = 100000000000000017,B;

ll solve(ll a, ll b)
{
      if (a<b)swap(a,b);

      if (a<A){
            A = a;
            B = b;
      }
}

int main()
{
      ll x;
      scanf("%I64d",&x);

      for (ll i=1 ; i*i<=x ; i++){
            if (x%i==0){

                  ll a = i , b = x/i;
                  ll gcd = __gcd(a,b);

                  b *= gcd;
                  solve(a,b);
            }
      }

      printf("%I64d %I64d\n",B,A);


      return 0;
}
