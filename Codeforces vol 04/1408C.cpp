#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n, l;
double A[100005];

double findAdis(double t)
{
      double vel = 1.0;

      for (int i=1 ; i<=n ; i++){
            double tm = (A[i]-A[i-1]) / vel;
            if (tm<=t){
                  t-=tm;
                  vel+=1.0;
            }
            else {
                  double s = vel*t;

                  //show(s);

                  return A[i-1]+s;
            }

//            show(i);
//            show(tm);
//            show(t);
      }

      return (double)A[n]+t*vel;
}
double findBdis(double t)
{
      double vel = 1.0;

      for (int i=n ; i>=1 ; i--){
            double tm = (A[i+1]-A[i])/vel;

            if (tm<=t){
                  t-=tm;
                  vel+=1.0;
            }
            else {
                  double s = vel*t;
                  return A[i+1]-s;
            }
      }
      return (double) A[1]-t*vel;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            cin >> n >> l;
            for (int i=1 ;i<=n ; i++)cin >>A[i];
            A[0] = 0;
            A[n+1] = (double) l;

//            show(findAdis(1));
//            show(findBdis(1));


            ll t = 64 ;
            double b = 1.0 , e = 1000000009.0 , mid;
            while(t--){

                  mid = (b+e)/2;
                  if (findAdis(mid)>=findBdis(mid)){
                        e = mid;
                        //show(mid);
                        //show(findAdis(mid));
                        //show(findBdis(mid));
                  }
                  else b = mid;
            }

            printf("%.15lf\n",mid);

      }

      return 0;
}
