#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

double v;

bool nonZero(double x)
{
      if ((ll)(x*1000000.0) > 0)return true;
      return false;
}

double Expected(double c, double m, double p)
{
//      cout << c << " " << m << " " << p << endl;
      double ret1 = 0 , ret2 = 0, ret3 = 0;

      //choosing C
      if (nonZero(c)){
            if (c>v){
                  if (nonZero(m))ret1 = (1.0 + Expected(c-v,m+v/2.0,p+v/2.0)) * c;
                  else ret1 = (1.0 + Expected(c-v,0.0,p+v)) * c;
            }
            else {
                  if (nonZero(m))ret1 = (1.0 + Expected(0,m+c/2.0,p+c/2.0)) * c;
                  else ret1 = (1.0 + Expected(0,0,p+c)) * c;
            }
      }

      //choose M
      if (nonZero(m)){
            if (m>v){
                  if (nonZero(c))ret2 = (1.0 + Expected(c+v/2.0,m-v,p+v/2.0)) * m;
                  else ret2 = (1.0 + Expected(0.0,m-v,p+v)) * m;
            }
            else {
                  if (nonZero(c))ret2 = (1.0 + Expected(c+m/2.0,0.0,p+m/2.0)) * m;
                  else ret2 = (1.0 + Expected(0.0,0.0,p+m)) * m;
            }
      }

      //choosing P
      ret3 = p;

//      cout << "-- " << ret1 << " " << ret2 << " " << ret3 << endl;

      return ret1+ret2+ret3;
}

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            double c,m,p;
            cin >> c >> m >> p >> v;
            printf("%.9lf\n",Expected(c,m,p));
      }

      return 0;
}
