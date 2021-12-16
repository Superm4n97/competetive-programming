#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll x = n%10 , y = 0;
            while(n){
                  y++;
                  n/=10;
            }

            cout << 10*(x-1) + y*(y+1)/2 << endl;
      }

      return 0;
}
