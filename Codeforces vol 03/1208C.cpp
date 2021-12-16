#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2005

using namespace std;

ll A[maxn][maxn] , n;

int main()
{
      cin >> n;

      ll number = 0;

      for(ll i=0 ; i<n ; i+=2){
            for (ll j=0; j<n; j+=2){
                        A[i][j] = number;
                        A[i+1][j] = number+1;
                        A[i][j+1] = number+2;
                        A[i+1][j+1] = number+3;
                        number+=4;
            }
      }

      for (int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                  cout << A[i][j] << " ";
            }
            cout << endl;
      }


      return 0;
}
