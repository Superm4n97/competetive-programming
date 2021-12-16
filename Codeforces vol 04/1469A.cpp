#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            string s;
            cin >> s;

            ll n = s.size() , cnt = 0, sol = 1;

            if (s[0]==')')sol = 0;
            if (s[n-1]=='(')sol = 0;
            if (n%2==1)sol = 0;

            if (sol)cout << "YES" << endl;
            else cout << "NO" << endl;
      }

      return 0;
}
