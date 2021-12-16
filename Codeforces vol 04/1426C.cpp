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

            ll temp = sqrt(n);
            ll ans = temp-1;

            ll div = (n+temp-1)/temp - 1;
            cout << div+ans << endl;
      }


      return 0;
}

