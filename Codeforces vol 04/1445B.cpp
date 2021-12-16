#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll a,b,c,d;
            cin >> a >> b >> c >> d;

            cout << max(a+b,c+d) << "\n";
      }

      return 0;
}
