#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;

            string s;
            cin >> s;

            if (n%2==1){
                  bool sol = false;
                  for (int i=0 ; i<n ; i+=2){
                        ll temp = s[i]-'0';
                        if (temp%2==1)sol = true;
                  }
                  cout << (sol?"1":"2") << endl;
            }
            else {
                  bool sol = false;
                  for (int i=1 ; i<n ; i+=2){
                        ll temp = s[i]-'0';
                        if (temp%2==0)sol = true;
                  }
                  cout << (sol?"2":"1")<< endl;
            }
      }

      return 0;
}
