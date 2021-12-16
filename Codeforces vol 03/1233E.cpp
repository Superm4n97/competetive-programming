#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc = 1;
      //cin >> tc;

      ll ans[] = {1, 3, 40, 1260, 72576, 6652800, 889574400, 163459296000, 39520825344000, 12164510040883200};

      while(tc--){

            ll n;
            cin >> n;

            cout << ans[(n/2)-1] << endl;
      }

      return 0;
}
