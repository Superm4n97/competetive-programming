#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,m,r;
      cin >> n >> m >> r;

      ll mn = 100000000 , mx = 0;
      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a;
            mn = min(mn,a);
      }
      for (int i=0 ; i<m ; i++){
            ll a;
            cin >> a;
            mx = max(mx,a);
      }

      ll ans = 0 , sh = r/mn;
      ans+=(r%mn);
      ans+=(sh*mx);
      cout << max(r,ans) << endl;

      return 0;
}
