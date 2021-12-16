#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll l,r;
            cin >> l >> r;
            ll temp = r/2 +1;
            if (temp>=l){
                  cout << r%temp << endl;
            }
            else cout << r%l << endl;
      }

      return 0;
}
