#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int A[105][105], R[105] , n;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            for (int i=0 ; i<=n+2 ; i++)
                  for (int j=0 ; j<=n+3 ; j++)A[i][j] = -5;
            memset(R,0,sizeof R);

            ll total = (n-1)/2 * 3;

            if (n%2==0){
                  for (int i=1 , j = n ; i<j ; i++,j--){
                        A[i][j] = 0;
                        R[i] = R[j] = 1;
                  }
                  total++;
            }

            show(total);

            for (int i=1 ; i<=n ; i++){
                  for (int j=i+1 ; j<=n ; j++){
                        if(A[i][j]<-1){
                              if (R[i]<total){
                                    R[i]+=3;
                                    A[i][j] = 1;
                              }
                              else {
                                    R[j]+=3;
                                    A[i][j] = -1;
                              }
                        }
                  }
                  show(R[i]);
            }

            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=n ; j++)cout << A[i][j] << " ";
                  cout << endl;
            }

            for (int i=1 ; i<=n ; i++){
                  for (int j=i+1 ; j<=n ; j++){
                        cout << A[i][j] << " ";
                  }
            }
            printf("\n");
      }


      return 0;
}
