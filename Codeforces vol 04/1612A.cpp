#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      scanf("%lld",&tc);

      while(tc--){
            ll x,y;
            cin >> x >> y;

            if (x%2 != y%2)cout << "-1 -1" << endl;
            else {
                  ll half = (x+y)/2;
                  if (x>=half)x = half , y = 0;
                  else y = half , x = 0;
                  cout << x << " " << y << endl;
            }
      }

      return 0;
}
