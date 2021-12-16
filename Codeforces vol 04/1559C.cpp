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

            ll A[n+6];
            for (int i=0 ; i<n ; i++)cin >>A[i];

            if (A[0]==1){
                  cout << n+1 << " ";
                  for (int i=1 ; i<=n ; i++)cout << i << " ";
                  cout << endl;
            }
            else if (A[n-1]==0){
                  for (int i=1 ; i<=n+1 ; i++)cout << i << " ";
                  cout << endl;
            }
            else {
                  ll x = 1;
                  for (int i=0 ; i<n ; i++){
                        if (x && A[i]==0 && A[i+1]==1){
                              x = 0;
                              cout << i+1 << " " << n+1 << " ";
                        }
                        else cout << i+1 << " ";
                  }
                  cout << endl;
            }
      }

      return 0;
}
