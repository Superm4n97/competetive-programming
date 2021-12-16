#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[505][505];

int main()
{
      ll n,m , x = 0;
      cin >> n >> m;

      x = n;

      if (n>m)swap(n,m);

      if (n==1 && m==1){
            cout << 0 << endl;
            return 0;
      }
      else {
            for (ll i=1 ; i<=n ; i++){
                  for (ll j=1 ; j<=m ; j++){
                        A[i][j] = i*(n+j);
                  }
            }
      }

      if (x==n){
            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++)cout << A[i][j] << " ";
                  cout << endl;
            }
      }
      else {
            for (int j = 1 ; j<=m ; j++){
                  for (int i = 1 ; i<=n ; i++)cout << A[i][j] << " ";
                  cout << endl;
            }
      }




      return 0;
}

