#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      string s;
      cin >> s;
      ll n = s.size();

      for (int i=0 ; i<n-1 ; i++){

            if (s[i]==s[i+1])cout << "0 ";
            else {
                  cout << "1 ";
            }
      }


      if (s[n-1] == 'a')cout << 1 << endl;
      else cout << 0 << endl;


      return 0;
}
