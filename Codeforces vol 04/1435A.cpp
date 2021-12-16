#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){

            ll n;
            cin >> n;

            ll A[n+6];
            for (int i=1 ; i<=n ; i++)cin >> A[i];

            for (int i=2 ; i<=n ; i+=2){
                  if ((A[i]<0 && A[i-1]<0) || (A[i]>0 && A[i-1]>0)){

                        cout << A[i] << " " << -A[i-1] << " ";
                  }
                  else {
                        cout << abs(A[i]) << " " << abs(A[i-1]) << " ";
                  }
            }
            cout << endl;
      }

      return 0;
}
