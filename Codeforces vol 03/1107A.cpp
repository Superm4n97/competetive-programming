#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << endl

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

            if (s.size()==2 && s[0]>=s[1])cout << "NO" << endl;
            else {
                  cout << "YES" << endl;
                  cout << "2\n";
                  cout << s[0] << " ";
                  for (int i=1 ; i<s.size() ;i++)cout << s[i];
                  cout << "\n";
            }
      }



      return 0;
}
