#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;
double c,m,pp,v , ans;

void rec(double x, double y, double p, double mv,double prob)
{
//      cout << x << " " << y << " " << p << " " << prob << endl;
      if (x>0){
            if (x<=v){
                  if (y>0)rec(0,y+x/2,p+x/2,mv+1,prob*x);
                  else rec(0,0,p+x,mv+1,prob*x);
            }
            else {
                  if (y>0)rec(x-v,y+v/2.0,p+v/2.0,mv+1,prob*x);
                  else rec(x-v,0,p+v,mv+1,prob*x);
            }
      }
      if (y>0){
            if (y<=v){
                  if (x>0)rec(x+y/2,0,p+y/2.0,mv+1,prob*y);
                  else rec(0,0,p+y,mv+1,prob*y);
            }
            else {
                  if (x>0)rec(x+v/2.0,y-v,p+v/2.0,mv+1,prob*y);
                  else rec(0,y-v,p+v,mv+1,prob*y);
            }
      }

//      show(p);
//      show(mv);
//      show(prob);
      ans += mv*prob*p;

}

int main()
{
      ll tc;
      scanf("%lld",&tc);
      while(tc--){
            ans = 0.0;
            cin >> c >> m >> pp >> v;
            rec(c,m,pp,1.0,1.0);
            printf("%.9lf\n",ans);
      }

      return 0;
}
