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
            cout << n-1 << endl;
            for (int i=2 ; i<=n ; i++)cout << i << " ";
            cout << endl;
      }

      return 0;
}
