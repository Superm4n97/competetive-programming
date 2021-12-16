#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            string s;
            cin >> s;

            ll n = s.size();
            if (s[n-1]%2 == 0)cout << 0 << endl;
            else if (s[0]%2 == 0)cout << 1 << endl;
            else {
                  ll ev = 0;
                  for (int i=0 ; i<n ; i++){
                        if (s[i]%2==0)ev = 1;
                  }
                  if (ev)cout << 2 << endl;
                  else cout << -1 << endl;
            }
      }

      return 0;
}
