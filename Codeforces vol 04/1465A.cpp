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
            ll n;
            cin >> n;

            string s;
            cin >> s;

            s.push_back(')');
            ll cnt = 0;
            for (int i = n-1 ; i>=0 ; i--){
                  if (s[i]==')' && s[i+1]==')')cnt++;
                  else break;
            }
            if (cnt>n-cnt)cout << "Yes" << endl;
            else cout << "No" << endl;
      }

      return 0;
}
