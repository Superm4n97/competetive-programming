#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "<< x << endl

using namespace std;

ll n,m , tc,g;

int main()
{
      cin >> n >> m >> tc;
      g = __gcd(n,m);

      while(tc--){

            ll sx,sy,ex,ey;
            cin >> sx >> sy >> ex >> ey;

            ll t1 , t2;

            if (sx==1){
                  ll dd = n/g;
                  t1 = (sy-1)/dd;
            }
            else {
                  ll dd = m/g;
                  t1 = (sy-1)/dd;
            }

            if (ex==1){
                  ll dd = n/g;
                  t2 = (ey-1)/dd;
            }
            else {
                  ll dd = m/g;
                  t2 = (ey-1)/dd;
            }

            if(t1==t2)cout << "YES" << endl;
            else cout << "NO" << endl;
      }


      return 0;
}
