#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            string s;
            cin >> s;
            ll n = s.size();

            ll l = 0 , r = n-1 , sol = 1;
            char ch = 'a'+(n-1);

            for (char c = ch ; c>='a' ; c--){
//                  show(c);
                  if (l>r)sol = 0;
                  if (s[l]==c)l++;
                  else if (s[r]==c)r--;
                  else sol = 0;
            }
            cout << (sol?"YES":"NO") << endl;
      }


      return 0;
}
