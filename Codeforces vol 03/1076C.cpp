#include <bits/stdc++.h>
#define ll              long long int
#define show(x)         cout << #x << " : " << x << endl

using namespace std;

ll n;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            cin >> n;

            if (n==0)cout << "Y 0 0" << endl;
            else if (n<4)cout << "N" << endl;
            else {
                  double d = n;
                  double b = 1 , e = 2 , ans = 0 , t = 60;

                  while(t--){
                        ans = (b+e)/2;

                        double x = d - ans;

                        if (x*ans<=d)b = ans;
                        else e = ans;
                  }

                  printf("Y %.9lf %.9lf\n",d - ans , ans);
            }
      }

      return 0;
}
/**

a.b = d
a+b = d
(a+b)^2 = a.a + b.b + 2.a.b = d.d

10
9  --- 9 -1
8.5--- 12 -1.5
8.75--10.93 -1.25
8.85--10.17 -1.15

*/
