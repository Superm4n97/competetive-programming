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
            string s;
            cin >> n;
            cin>> s;

            ll pos = 0 , neg = 0;

            for (int i=1; i<n ; i++){

                  if (s[i]==s[i-1]){
                        if (s[i]=='0')neg++;
                        else pos++;
                  }
            }

            cout << max(neg,pos) << "\n";
      }

      return 0;
}
