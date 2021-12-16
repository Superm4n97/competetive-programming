#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll X[2*n+5] , Y[2*n+5] , A[n+5];

            for (int i=1 ; i<=2*n ; i++){
                  if (i<=n){
                        X[i] = i;
                        Y[i] = n-i+1;
                  }
                  else {
                        X[i] = X[i-n];
                        Y[i] = Y[i-n];
                  }
            }

            //for (int i=1 ; i<=n ; i++)cout << " " << Y[i] ;

            for (int i=1 ; i<=n ; i++)cin >> A[i];

            bool sol = false;

            for (int i=1 ; i<=n ; i++){

                  bool a = true, b = true;

                  for (int j = 1 ; j<=n ; j++){

                        if (X[i+j-1] != A[j])a = false;
                        if (Y[i+j-1] != A[j])b = false;
                  }
                  if (a || b)sol = true;
            }

            cout << (sol?"YES":"NO") << endl;
      }


      return 0;
}
