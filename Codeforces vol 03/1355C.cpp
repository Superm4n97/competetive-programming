#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll segmentCalculation(ll x, ll y, ll a, ll b)
{

      if (b<x){
            return (y-x+1)*(b-a+1);
      }
      if (a>y)return 0;

      ll pre = 0;

      if (x<a)x = a;
      if (b>y)b = y;

      if (a<x){
            ll temp = x-a;
            a = x;
            ll t1 = y-x+1;
            pre = t1*temp;
      }

      if (x<=a && y>=b){
            x = a;
            ll t1 = y-x+1 , t2 = b-a+1;

            t2 = t1 - t2;
            return t1*(t1+1)/2 - t2*(t2+1)/2+pre;
      }
}

int main()
{
      ll a,b,c,d , ans = 0;
      cin >> a >> b >> c >> d;

      for (int i=b ; i<=c ; i++){
            ll x = c - i+1 , y = d - i+1;
            ans += segmentCalculation(a,b,x,y);
      }
      cout << ans << endl;


      return 0;
}
