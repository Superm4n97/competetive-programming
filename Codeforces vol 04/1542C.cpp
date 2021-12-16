#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout<< #x << " : " << x << endl
#define mod 1000000007

using namespace std;

ll A[]={2,3,2,5,7,2,3,11,13,2,17,19,23,5,3,29,31,2,37,41,43};
ll X[]={3,4,5,7,8,9,11,13,16,17,19,23,25,27,29,31,32,37,41,43};

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll mul(ll a, ll b)
{
      return amod(amod(a)*amod(b));
}

int main()
{
      ll tc;
      scanf("%lld",&tc);
      while(tc--){
            ll n;
            scanf("%lld",&n);

            ll m = 1, pre = 2 , rem, ans = amod(n*2);
            for (ll i=0 ; i<20 ; i++){
                  m*=A[i];
                  ll rem = n / m;
                  if (rem==0)break;
                  ll temp = mul(rem,pre);
                  ans-=temp;
                  if (ans<0)ans+=mod;

                  temp = mul(rem,X[i]);
                  ans = amod(ans+temp);

                  pre = X[i];
            }
            printf("%lld\n",ans);
      }


      return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
2 3 2 3 2 4 2 3 2  3  2  5  2  3  2  3  2  4  2  3  2  3  2  5  2  3  2  3  2  4

*/
