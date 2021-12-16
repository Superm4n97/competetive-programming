#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            string s;
            cin >> s;

            ll alter = 0;
            for (int i=1 ; i<s.size() ; i++){
                  if (s[i]!=s[i-1])alter++;
            }

            if (alter==0 && s[0]=='1')cout << 0 << endl;
            else if (alter<=1 || (s[0]=='1' && alter==2))cout << 1 << endl;
            else cout << 2 << endl;
      }

      return 0;
}
