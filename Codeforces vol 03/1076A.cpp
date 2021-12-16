#include <bits/stdc++.h>
#define ll              long long int
#define show(x)         cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;
      string s;
      cin >> s;

      bool ok = false;

      for (int i=0 ; i<n-1 ; i++){

            if(s[i]>s[i+1] && !ok){
                  ok = true;
            }
            else cout << s[i];
      }

      if (ok)cout << s[n-1] ;


      return 0;
}
/**
aaccdd
aacced
dbca
*/
