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

            ll A[n+5] , B[n+5] , C[n+5], P[n+5];

            for (int i=1 ; i<=n ; i++)cin >> A[i];
            for (int i=1 ; i<=n ; i++)cin >> B[i];
            for (int i=1 ; i<=n ; i++)cin >> C[i];

            P[1] = A[1];

            for (int i=2 ; i<=n ; i++){
                  if (i==n){
                        if (A[i]!=P[1] && A[i]!=P[n-1])P[i] = A[i];
                        else if (B[i]!=P[1] && B[i]!=P[n-1])P[i] = B[i];
                        else P[i] = C[i];
                  }
                  else {
                        if (A[i]==P[i-1])P[i] = B[i];
                        else P[i] = A[i];
                  }
            }
            for (int i=1 ; i<=n ; i++)cout << P[i] << " ";
            cout << endl;
      }

      return 0;
}
