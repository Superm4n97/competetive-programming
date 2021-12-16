#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      //cout << " ok " << endl;
      ll n;
      cin >> n;

      ll ans = 0;

      for (int i=0 ; i<n; i++){

            ll a,b;
            cin >> a >> b;

            ans = max(ans,a+b);
      }

      cout << ans << endl;


      return 0;
}

/**

**/
