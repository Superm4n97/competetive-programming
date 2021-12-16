#include<bits/stdc++.h>
#define ll long long int

using namespace std;

string f = "op";
string jf = "used";
string js = "usam";
string k = "adinm";

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            string s;
            cin >> s;

            reverse(s.begin() , s.end());
            string st = s.substr(0,2);

            if (st == f){
                  cout << "FILIPINO" << endl;
            }
            else {
                  string st = s.substr(0,4);

                  if (st==jf || st==js)cout << "JAPANESE" << endl;
                  else {
                        cout << "KOREAN" << endl;
                  }
            }
      }

      return 0;
}
