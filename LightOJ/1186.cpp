#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      for (int t=1 ; t<=tc; t++){

            ll n;
            cin >> n;

            ll A[n+5] , xr = 0;
            for (int i=0 ; i<n ; i++){
                  cin >> A[i];
            }
            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  ll temp = a-A[i]-1;
                  xr = xr^temp;
            }

            cout << "Case "<<t<<": ";
            if (xr)cout << "white wins"<<endl;
            else cout << "black wins" << endl;

      }


      return 0;
}
