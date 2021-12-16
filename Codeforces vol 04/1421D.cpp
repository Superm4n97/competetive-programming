#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll c1,c2,c3,c4,c5,c6 , x,y;
            cin >> x >> y;
            cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

//            if (c1>c2+c6)c1 = c2+c6;
//            if (c4>c3+c5)c4 = c3+c6;

            ll t1 = 0 , t2 = 0 , t3 = 0;
            {
                  if (x>0)t1+=abs(x*c6);
                  else t1 += abs((-x)*c3);

                  if (y>0)t1 += abs(c2*y);
                  else t1 += abs(c5*(-y));
            }
            {
                  if (x>0){
                        t2 += abs(x*c1);
                        ll temp = y-x;

                        if (temp>0)t2+=abs(temp*c2);
                        else t2+=abs((-temp)*c5);
                  }
                  else {
                        t2 += abs((-x)*c4);
                        ll temp = y-x;

                        if (temp>0)t2+=abs(temp*c2);
                        else t2+=abs((-temp)*c5);
                  }
            }
            {
                  if (y>0){
                        t3 += abs(y*c1);
                        ll temp = x-y;

                        if (temp>0)t3+=abs(temp*c6);
                        else t3 += abs((-temp)*c3);
                  }
                  else {
                        t3 += abs((-y)*c4);
                        ll temp = x-y;

                        if (temp>0)t3+=abs(temp*c6);
                        else t3 += abs((-temp)*c3);
                  }
            }

            cout << min(t1,min(t2,t3)) << "\n";
      }

      return 0;
}
