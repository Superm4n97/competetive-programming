#define maxn 300005
#define ll long long
#define mod 1000000007
#define pb push_back
#include<bits/stdc++.h>
using namespace std;


//ll mul(ll x, ll y){
//    ll res = (x%mod * y%mod)%mod;
//    return res;
//}

ll sum(ll x, ll y){
    ll res = (x%mod + y%mod)%mod;
    return res;
}

ll LCM(ll a, ll b){
    ll gcd = __gcd(a, b);
    return (a*b)/gcd;
}


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

ll R(ll n)
{
//      ll tc;
//      scanf("%lld",&tc);
//      while(tc--){
//            ll n;
//            scanf("%lld",&n);

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
            return ans;
//            printf("%lld\n",ans);
//      }


      return 0;
}

int main(){
    int tc = 1000000;
//    cin >> tc;
    for(ll ii=1;ii<=tc;ii++){
        ll n = ii;
//        cin >> n;
        ll res = 0, lcm = 1;
        res = sum(n, n);
        for(ll i=2;i<=10000000000000000;i++){
            lcm = LCM(i, lcm);
            if(lcm > n) break;
            res = sum(res, n/lcm);

        }
        if (res!=R(ii))cout << " error : " << ii << endl;
    }

    return 0;
}
