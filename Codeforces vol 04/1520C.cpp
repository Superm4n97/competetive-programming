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

            if (n==1)cout << 1 << endl;
            else if (n==2)cout << -1 << endl;
            else {
                  ll A[n+3][n+3] , cnt = 1;
                  for (int i=1 ; i<=n ; i++){
                        for (int j=1 ; j<=n ; j++){
                              A[i][j] = cnt;
                              cnt++;
                        }
                  }

                  for (int j=1 ; j<=n ; j+=2){
                        for (int i=2 ; i<=n ; i++){
                              swap(A[i][j],A[i-1][j]);
                        }
                  }

                  for (int i=1 ; i<=n ; i++){
                        for (int j=1 ; j<=n ; j++)cout << A[i][j] << " ";
                        cout << endl;
                  }
            }
      }


      return 0;
}
/*
2 = -1
4 2 6
1 5 3
7 8 9
*/
