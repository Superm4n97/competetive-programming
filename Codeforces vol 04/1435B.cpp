#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){

            ll n,m;
            cin >> n >> m;

            ll A[n+4][m+5] , col[n*m+5];

            for (int i=1 ; i <=n ; i++){
                  for (int j=1 ; j<=m ; j++){

                        ll a;
                        cin >> a;

                        col[a] = j;
                  }
            }

            for (int j=1 ; j<=m ; j++){
                  for (int i=1 ; i<=n ; i++){

                        ll a;
                        cin >> a;

                        A[i][col[a]] = a;
                  }
            }

            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++)cout << A[i][j] << " ";
                  cout << "\n";
            }
      }

      return 0;
}
