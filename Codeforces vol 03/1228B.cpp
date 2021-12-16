#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

ll A[1004][1004] , r[1005];

int main()
{
      ll n,m;
      cin >> n >> m;

      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a;
            r[i] = a;

            for (int j=0 ; j<=a ; j++){
                  A[i][j] = 1;
            }
      }

      bool sol = true;

      for (int j=0 ; j<m ; j++){
            ll a;
            cin >> a;

            for (int i=0 ; i<=a ; i++){
                  if (r[i]==j && i<a){
                        //cout << "   1\n";
                        //show(r[i]);
                        //show(j);
                        sol = false;
                  }
                  A[i][j] = 1;
            }

            if (r[a]>j){
                  sol = false;
                  //cout << "   2\n";
                  //show(a);
            }
      }

      if (!sol){
            cout << 0 << endl;
            return 0;
      }

      ll ans = 1;

      for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                  if (A[i][j]==0){
                        ans*=2;
                        ans%=mod;
                  }
            }
      }

      cout << ans << endl;


      return 0;
}
