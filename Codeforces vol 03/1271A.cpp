#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll a,b,c,d,e,f;
      cin >> a >> b >> c >> d >> e >> f;

      ll ans = 0;
      for (ll i = 0 ; i<=d ; i++){
            ans = max(ans,min(a,i)*e+min(d-i,min(b,c))*f);
      }
      cout << ans << endl;


      return 0;
}
