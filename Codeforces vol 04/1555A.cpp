#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            if (n<=6){
                  cout << 15 << endl;
                  continue;
            }
            n-=6;
            cout << 15 + (n+1)/2 * 5 << endl;
      }

      return 0;
}
