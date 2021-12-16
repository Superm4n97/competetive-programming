#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll x(char ch)
{
      if (ch=='0')return 0;
      return 1;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,c[5],h;
            cin >> n >> c[0] >> c[1] >> h;

            string s;
            cin >> s;

            ll ans = 0;

            for (int i=0 ; i<n; i++){
                  ans+=min(c[x(s[i])],c[1-x(s[i])]+h);
            }
            cout << ans << endl;
      }

      return 0;
}
