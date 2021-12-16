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

            n+=n;

            ll A[n+5] , xr = 0;
            for (int i=0 ; i<n ; i++){
                  cin >> A[i];
            }

            for (int i=1 ; i<n ; i+=2){
                  ll temp = A[i]-A[i-1]-1;
                  xr = xr^temp;
            }

            cout << "Case "<<t<<": ";
            if (xr)cout << "Alice"<<endl;
            else cout << "Bob" << endl;

      }


      return 0;
}
