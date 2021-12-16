#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[105][105] , n , m , fx[105][105];

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            cin >> n >> m;
            for (int i=1 ; i<=n ; i++){
                  for (int j = 1;  j<=m ; j++){
                        cin >> A[i][j];
                        if ((i+j)%2==1 && A[i][j]%2==0)A[i][j]++;
                        if ((i+j)%2==0 && A[i][j]%2==1)A[i][j]++;
                  }
            }
            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++)cout << A[i][j] << " ";
                  cout << endl;
            }
      }


      return 0;
}
