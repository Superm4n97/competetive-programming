#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,m;
      cin >> n >> m;

      string s[n+6];

      int L = m , R = -1, U = n , D = -1 , black = 0;

      for (int i=0 ; i<n ; i++){
            cin >> s[i];

            for (int j = 0 ; j<m ; j++){
                  if (s[i][j]=='B'){
                        L = min(L,j);
                        R = max(R,j);
                        U = min(U,i);
                        D = max(D,i);
                        black++;
                  }
            }
      }

      if (L==m){
            cout << 1 << endl;
            return 0;
      }

      //cout << L << R << U << D << endl;

      ll hori = R-L+1 , ver = D-U+1;

      if (max(hori,ver)>n || max(hori,ver)>m){
            cout << -1 << endl;
      }
      else {
            cout << max(hori,ver)*max(hori,ver) - black << endl;
      }

      return 0;
}
/**

**/
