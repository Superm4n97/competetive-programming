#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc = 1;
      cin >> tc;
      while(tc--){

            ll a,b;
            cin >> a >> b;

            a = abs(a-b);

            ll ans = a/10;
            if (a%10)ans++;

            cout << ans << endl;
      }

      return 0;
}
/**

**/
