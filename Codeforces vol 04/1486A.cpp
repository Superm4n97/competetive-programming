#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;

            ll A[n+5];

            for (int i=0 ; i<n ; i++)cin >> A[i];

            bool sol = true;

            for (int i=0 ; i<n; i++){
                  if (A[i]>=i)A[i+1] += (A[i]-i);
                  else sol = false;
            }
            cout << (sol?"YES":"NO") << endl;
      }


      return 0;
}
