#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll x, y;
            cin >> x>> y;

            if (x>=y)cout << "YES" << endl;
            else if (x==1)cout << "NO" << endl;
            else if (x<=3 && y<=3)cout << "YES" << endl;
            else if (x<=3)cout << "NO" << endl;
            else cout << "YES" << endl;
      }


      return 0;
}
