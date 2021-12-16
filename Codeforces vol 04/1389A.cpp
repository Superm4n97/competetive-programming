#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll a,b;
            cin >> a >> b;

            if (a*2<=b)cout << a << " " << 2*a << endl;
            else cout << -1 << " " << -1 << endl;
      }
}
