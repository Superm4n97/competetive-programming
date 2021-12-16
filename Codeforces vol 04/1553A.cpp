#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            ll ans = 0;
            if (n%10==9)ans = 1;
            n/=10;
            ans+=n;
            cout << ans << endl;
      }

      return 0;
}
