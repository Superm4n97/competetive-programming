#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000010

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5] , B[n+6] , mnL[n+6];

            for (int i=1 ; i<=n ; i++){
                        cin >> A[i];
                        B[i] = A[i];
            }

            for (int i=2 ; i<=n ; i++){
                  if (A[i]>A[i-1]){
                        ll k = i;
                        ll temp = A[i] - A[i-1];
                        while(A[k]-A[i-1]>=temp && k<=n){
                              temp = A[k] - A[i-1];
                              A[k]-=A[i-1];
                              k++;
                        }
                        for (int j = 1 ; j<i ; j++)A[j] = 0;
//                        show(i);
//                        show(A[i]);
                        break;
                  }

                  if (i==n){
                        for (int j=1 ; j<=n ; j++)A[j] = 0;
                  }
            }

            for (int i = n-1 ; i>=1 ; i--){
                  if (A[i]>A[i+1]){
                        ll k = i;
                        ll temp = A[i]-A[i+1];

                        while(A[k]-A[i+1]>=temp && k>=1){
                              temp = A[k]-A[i+1];
                              A[k]-=A[i+1];
                              k--;
                        }

                        for (int j=n ; j>i ; j--)A[j] = 0;
                        break;
                  }
                  if (i==1){
                        for (int j=1 ; j<=n ; j++)A[j] = 0;
                  }
            }
            bool sol1 = true;
            for (int i=1 ; i<=n ; i++){
                  if (A[i])sol1 = false;
            }

            ///************************

            for (int i = n-1 ; i>=1 ; i--){
                  if (B[i]>B[i+1]){
                        ll k = i;
                        ll temp = B[i]-B[i+1];

                        while(B[k]-B[i+1]>=temp && k>=1){
                              temp = B[k]-B[i+1];
                              B[k]-=B[i+1];
                              k--;
                        }

                        for (int j=n ; j>i ; j--)B[j] = 0;
                        break;
                  }
                  if (i==1){
                        for (int j=1 ; j<=n ; j++)B[j] = 0;
                  }
            }

            for (int i=2 ; i<=n ; i++){
                  if (B[i]>B[i-1]){
                        ll k = i;
                        ll temp = B[i] - B[i-1];
                        while(B[k]-B[i-1]>=temp && k<=n){
                              temp = B[k] - B[i-1];
                              B[k]-=B[i-1];
                              k++;
                        }
                        for (int j = 1 ; j<i ; j++)B[j] = 0;
//                        show(i);
//                        show(A[i]);
                        break;
                  }

                  if (i==n){
                        for (int j=1 ; j<=n ; j++)B[j] = 0;
                  }
            }

            bool sol2 = true;
            for (int i=1 ; i<=n ; i++){
                  if (B[i])sol2 = false;
            }
            ///******8888888888888888888

            cout << ((sol1|sol2)?"YES":"NO") << endl;
      }

      return 0;
}
