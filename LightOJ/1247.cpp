#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      for (int t=1 ; t<=tc; t++){

            ll n , m, xr = 0;
            cin >> n;

            for (int i=0 ; i<n ; i++){

                  ll temp = 0;
                  cin >> temp;
                  xr =xr ^ temp;
            }

            cout << "Case "<<t<<": ";
            if (!xr)cout << "Alice"<<endl;
            else cout << "Bob" << endl;

      }


      return 0;
}
