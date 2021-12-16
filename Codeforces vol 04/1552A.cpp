#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%I64d",&w)
#define show(x)         cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;
            string s;
            cin >> s;
            string t = s;

            sort(s.begin(),s.end());

            ll ans = 0;

            for (int i=0 ; i<n ; i++){
                  if (s[i]!=t[i])ans++;
            }
            cout << ans << endl;
      }

      return 0;
}

/**

*/
