#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){

            ll a,b,x,y,n;
            cin >> a >> b >> x >> y >> n;

            ll ans1 , ans2 , m = n;

            {
                  ll tut = min(a-x , n);
                  ll _a = a - tut;

                  n-=tut;

                  tut = min(b-y,n);
                  ll _b = b - tut;

                  ans1 = _a*_b;
            }
            {
                  ll tut = min(b-y , m);
                  ll _b = b - tut;

                  m-=tut;

                  tut = min(a-x , m);
                  ll _a = a-tut;

                  ans2 = _a*_b;
            }

            cout << min(ans1,ans2) << endl;
      }

      return 0;
}
/**

**/
