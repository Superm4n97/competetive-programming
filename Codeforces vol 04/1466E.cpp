#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define mod 1000000007

using namespace std;

ll P[70];

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll summation(ll a, ll b)
{
      a = amod(a) , b = amod(b);
      a+=b;
      return amod(a);
}

ll multiplication(ll a, ll b)
{
      a = amod(a) , b = amod(b);
      a*=b;
      return amod(a);
}

int main()
{
      P[0] = 1;
      for (ll i=1 ; i<63 ; i++)P[i] = P[i-1]*2;

      ll tc;
      scl(tc);

      while(tc--){

            ll n;
            scl(n);

            ll A[n+5] , bit[70];
            memset(bit,0,sizeof bit);

            for (ll i=1 ; i<=n ; i++){
                  scl(A[i]);
                  ll a = A[i];
                  for (ll j = 0 ; j<62 ; j++){
                        if (a&1){
                             bit[j]++;
                        }
                        a/=2;
                  }
            }

            ll ans = 0;

            for (ll i=1 ; i<=n ; i++){
                  ll a = A[i] , mul = 0 , sum = 0;
                  for(ll j=0  ;j<62 ; j++){
                        if (a&1){
                              mul += multiplication(bit[j],P[j]);
                              mul = amod(mul);

                              sum += multiplication(P[j],n);
                              sum = amod(sum);
                        }
                        else {
                              sum += multiplication(bit[j],P[j]);
                              sum = amod(sum);
                        }

                        a/=2;
                  }

                  ans += multiplication(mul,sum);
                  ans = amod(ans);
            }
            printf("%I64d\n",ans);
      }


      return 0;
}
