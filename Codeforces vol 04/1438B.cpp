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

            map<ll,ll> mp;
            bool sol = false;

            for (int i=0 ; i<n ; i++){

                  ll a;
                  cin >> a;
                  mp[a]++;
                  if (mp[a]>1)sol = true;
            }

            if (sol)cout << "YES" << endl;
            else cout << "NO" << endl;
      }


      return 0;
}
