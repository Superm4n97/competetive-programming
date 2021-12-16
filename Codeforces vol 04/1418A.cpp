#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll x,y,k;
            cin >> x >> y >> k;

            ll ans = (k*y + k - 1 + x-2) / (x-1);

            cout << ans+k << endl;
      }


      return 0;
}
