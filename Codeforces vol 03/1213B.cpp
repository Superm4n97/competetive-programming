#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin>> n;

            ll A[n+5];
            for (int i=1 ; i<=n ; i++)cin >>A[i];

            ll ans = 0 , mn= 10000000000;

            for (int i=n ; i>=1 ; i--){
                  if (A[i]>mn)ans++;
                  else mn = A[i];
            }

            cout << ans << endl;
      }


      return 0;
}
