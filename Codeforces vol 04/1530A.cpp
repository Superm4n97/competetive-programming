#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);
      while(tc--){
            ll n;
            cin >> n;
            ll ans = 1;
            while(n){
                  ll d = n%10;
                  n/=10;
                  ans = max(ans,d);
            }
            cout << ans << endl;
      }

      return 0;
}
