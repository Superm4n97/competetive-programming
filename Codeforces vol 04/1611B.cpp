#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll a,b;
            cin >> a >> b;
            if (a>b)swap(a,b);

            ll teams = (a+b)/4;
            if (teams>a)cout << a << endl;
            else cout << teams << endl;
      }


      return 0;
}
