#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll check(char ch)
{
      if (ch=='a')return 1;
      return 0;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            string s;
            ll n;
            cin >> n;
            cin >> s;

            ll l = -1 , r = -1 , sol = 0;
            for (int i=1 ; i<n ; i++){
                  if (check(s[i]) != check(s[i-1])){
                        sol = 1;
                        l = i;
                        r = i+1;
                        break;
                  }
            }

            cout << l << " " << r << endl;

      }

      return 0;
}
