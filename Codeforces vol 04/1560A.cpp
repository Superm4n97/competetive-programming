#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll k;
            cin >> k;

            if (k==1){
                  cout << "1 1" << endl;
            }
            else {
                  ll r = sqrt(k-1);
                  ll x = r, y = r;

                  if (r*r+r+1>=k)x = k-(r*r+1);
                  else y = (r+1)*(r+1) - k;
                  cout << x+1 << " " << y+1 << endl;
            }
      }

      return 0;
}
