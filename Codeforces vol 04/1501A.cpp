#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[105] , B[105], a[105] , b[105] , T[105] , n;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            for (int i = 1 ; i<=n ; i++)cin >> A[i] >> B[i];
            for (int i = 1 ; i<=n ; i++)cin >> T[i];

            ll stay;

            for (int i=1 ; i<=n ; i++){
                  a[i] = b[i-1] + A[i] - B[i-1] + T[i] , stay = (B[i]-A[i]+1)/2;
                  if (B[i]-a[i] < stay) b[i] = a[i] + stay;
                  else b[i] = B[i];
            }
            cout << a[n] << endl;
      }

      return 0;
}
