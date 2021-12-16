#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll mp[n+5] , B[n+4];

      for (ll i=1 ; i<=n; i++){
            ll a;
            cin >> a;
            mp[a] = i;
      }

      for (int i=1 ; i<=n ; i++)cin >> B[i];

      ll mn = n+3 , ans = 0;

      for (int i=n ; i>=1 ; i--){

            if (mp[B[i]]>mn)ans++;
            else mn = mp[B[i]];
      }
      cout << ans << endl;


      return 0;
}
