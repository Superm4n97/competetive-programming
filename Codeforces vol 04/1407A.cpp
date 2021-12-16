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

            ll A[n+5] , cnt[n+5];

            ll one = 0 , zero = 0;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  if (A[i]==0)zero++;
                  else one++;
            }

            if (zero>=one){
                  cout << zero << endl;
                  for (int i=0 ; i<zero ; i++)cout << "0 ";
                  cout << endl;
            }
            else {
                  if (one%2)one--;
                  cout << one << endl;
                  for (int i=0 ; i<one; i++)cout << "1 ";
                  cout << endl;
            }
      }


      return 0;
}
