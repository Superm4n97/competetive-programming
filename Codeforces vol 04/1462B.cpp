#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

bool chck(string s)
{
      if (s=="2020")return true;
      return false;
}
ll n;
string s;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){

            cin >> n;
            cin >> s;
            bool sol = false;

            if (n<4){
                  cout << "NO" << endl;
                  continue;
            }

            for (int i=0 ; i<=4 ; i++){
                  string t;
                  for (int j = 0 ; j<i ; j++)t.push_back(s[j]);
                  for (int j=4-i-1 ; j>=0 ; j--)t.push_back(s[n-j-1]);

                  //show(t);

                  if (chck(t))sol = true;
            }

            cout << (sol?"YES":"NO") << endl;
      }

      return 0;
}
