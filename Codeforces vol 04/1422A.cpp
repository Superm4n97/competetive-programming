#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll a,b,c,d = 0;
            cin >> a >> b >> c ;
            cout << max(a,max(b,c)) << endl;
      }

      return 0;
}
