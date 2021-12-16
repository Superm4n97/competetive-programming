#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin>> tc;

      for (int _t = 1 ; _t<=tc ; _t++){
            ll x;
            string s;
            cin >> x >> s;

            cout << "Case "<<_t<<": ";
            if (s=="Alice"){
                  if ((x-1)%3==0)cout <<"Bob" << endl;
                  else cout << "Alice" << endl;
            }
            else {
                  if (x%3==0)cout << "Alice" << endl;
                  else cout << "Bob" << endl;
            }
      }


      return 0;
}
