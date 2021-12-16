#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

ll cal(ll lim)
{
      ll temp = 0 , ret = 0 , even = 2 , odd = 1;
      for (ll i =1 , j = 1 ; ; i*=2 , j++){

            if (temp>=lim)break;

            if (temp+i>=lim){

                  ll n = lim - temp;
                  n%=mod;

                  if (j%2){
                        ret += (n*(((odd%mod)+(n-1))%mod))%mod;
                        ret%=mod;
                        odd = odd+(n*2);
                  }
                  else {
                        ret += (n*(((even%mod)+(n-1))%mod))%mod;
                        ret%=mod;
                        even = even+(n*2);
                  }

                  temp = lim;
            }
            else {
                  ll n = i;
                  temp+=i;

                  n%=mod;

                  if (j%2){
                        ret += (n*(((odd%mod)+(n-1))%mod))%mod;
                        ret%=mod;
                        odd = odd+(n*2);
                  }
                  else {
                        ret += (n*(((even%mod)+(n-1))%mod))%mod;
                        ret%=mod;
                        even = even+(n*2);
                  }
            }
      }

      return ret;
}


int main()
{

      ll l,r;
      cin >> l >> r;
      ll ans = (cal(r)+mod-cal(l-1))%mod;

      cout << ans << endl;


      return 0;
}
