#include <bits/stdc++.h>
#define ll              long long int
#define show(x)         cout << #x << " : " << x << endl

using namespace std;

ll n;

int main()
{
      cin >> n;

      ll div = n;

      for (ll i=2 ; i*i<=n ; i++){

            if (n%i==0){
                  div = i;
                  break;
            }
      }

      if (div==n)cout << 1 << endl;
      else {
            if (div!=2){
                  ll ans = 1;
                  n-=div;

                  ans += n/2;

                  cout << ans << endl;
            }
            else {
                  cout << n/2 << endl;
            }
      }

      return 0;
}
/**
12 => 2,2,3
10 => 2,5
8 => 2,2,2
6 => 2,3
4 => 2,2


11=> 11

9 - 3,3
6 - 2,3


25 - 5,5
20 - 2,2,5

*/
