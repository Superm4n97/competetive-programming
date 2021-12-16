#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n, odd = 0;

      cin >> n;

      ll A[n+6];

      for (int i=1 ; i<=n ; i++){

            cin >> A[i];
            if (A[i] % 2)odd++;
      }

      if (A[1]%2 && A[n]%2 && n%2)cout << "Yes" << endl;
      else cout << "No" << endl;


      return 0;
}
/**

**/
