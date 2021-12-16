#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;

            if (n<15){
                  cout << "NO" << endl;
                  continue;
            }

            ll rem = n %14;

            if (rem>=1 && rem<=6)cout << "YES" << endl;
            else cout << "NO" << endl;
      }


      return 0;
}
