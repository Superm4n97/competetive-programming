#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            string s;
            cin >> s;

            ll n = s.size();

            ll a = 0 , b = 0;
            for (int i=0 ; i<n ; i++){

                  if (s[i]=='A')a++;
                  else {
                        if (a)a--;
                        else if (b)b--;
                        else b++;
                  }
            }

            if (a)cout << a+b << endl;
            else cout << b << endl;
      }

      return 0;
}
