#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005
#define mod 1000000007

using namespace std;

ll seq[maxn] , pw[maxn] , n , ans = 0;
string s;

int main()
{
      cin >> s;
      n = s.size();

      seq[1] = pw[0] = 1;
      for (ll i = 1 ; i<maxn; i++)pw[i] = (pw[i-1]*10)%mod;
      for (ll i = 2 ; i<maxn; i++)seq[i] = ((i*pw[i-1])%mod + seq[i-1])%mod;

      for (ll i = 0 ; i<n ; i++){

            ll a = s[i] - '0' , j = n-i-1;
            if(i>0) {

                  ll temp = (i*(i+1)/2) % mod;
                  temp %= mod;
                  temp *= pw[j];
                  temp %= mod;
                  temp *= a;
                  temp %= mod;
                  ans += temp;
                  ans %= mod;
            }
            if (i<n-1) {

                  ll temp = seq[j]*a;
                  temp %= mod;
                  ans += temp;
                  ans %= mod;
            }
      }

      cout << ans << endl;

      return 0;
}
/***
5*1000*1
5*100*2
5*10*3
5*1*4

10000 1000 100 10 1
1     2    3   4  5

10^n-1 * n-1

***/
