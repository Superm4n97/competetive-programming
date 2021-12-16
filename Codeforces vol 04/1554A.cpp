#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%I64d",&w)
#define show(x)         cout << #x << " : " << x << endl

using namespace std;


int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            ll A[n+5];

            for (int i=1 ; i<=n ; i++)cin >> A[i];

            ll ans = 0;
            for (int i=2 ; i<=n ; i++){
                  ans = max(ans,A[i]*A[i-1]);
            }
            cout << ans << "\n";
      }

      return 0;
}

/**

*/
