#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll a,b;
            cin >> a >> b;

            if (b<2*a)cout << "YES" << endl;
            else cout << "NO" << endl;
      }

      return 0;
}
