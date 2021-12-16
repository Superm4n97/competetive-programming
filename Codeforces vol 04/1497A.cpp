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

            ll A[n+5];
            for (int i=0 ; i<n ; i++){
                  cin >> A[i];
            }

            for (int i=0 ; i<n ; i++){
                  for (int j=i ; j<n ; j++){
                        if (A[j]==i){
                              swap(A[i],A[j]);
                              break;
                        }
                  }
            }

            for (int i=0 ; i<n ; i++)cout << A[i] << " ";
            cout << endl;
      }

      return 0;
}
