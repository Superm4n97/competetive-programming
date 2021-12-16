#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll x[5] , y[5], dis;
            for (int i=0 ; i<3 ; i++)cin >> x[i]>> y[i];

            if (x[0]==x[1]){
                  if (x[2]==x[1] && y[2]>min(y[0],y[1]) && y[2]<max(y[0],y[1]))dis = abs(y[1]-y[0])+2;
                  else dis = abs(y[1]-y[0]);
            }
            else if (y[0]==y[1]){
                  if (y[2]==y[1] && x[2]>min(x[0],x[1]) && x[2]<max(x[0],x[1]))dis = abs(x[1]-x[0])+2;
                  else dis = abs(x[1]-x[0]);
//                  show(dis);
            }
            else dis = abs(x[0]-x[1])+abs(y[0]-y[1]);
            cout << dis << endl;
      }

      return 0;
}
