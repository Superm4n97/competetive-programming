#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "  << x << endl

using namespace std;

int main()
{
      int tc = 1;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;

            ll A[n+5] , B[n+5] , C[n+5] , x  = -1;
            bool solution = true;

            for (int i=1 ; i<=n ; i++)cin >> A[i];
            for (int i=1 ; i<=n ; i++)cin >> B[i];

            for (int i=1 ; i<=n ; i++){

                  C[i] = B[i] - A[i];
                  if (C[i]<0)solution = false;

                  if (C[i]!=0){
                        if (x==-1)x = C[i];
                        else {
                              if (C[i]!=x)solution = false;
                        }
                  }
            }

            x = 0;
            if (C[1]!=0)x =1;

            for (int i=2 ; i<=n; i++){
                  if (C[i]!=C[i-1])x++;
            }

            if (x>2)solution = false;

            cout << (solution?"YES":"NO") << endl;
      }
}
