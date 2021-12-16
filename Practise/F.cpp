#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

pair<ll,ll> rec(ll n, ll m)
{
      if (n==2){
            if (m==1)return {0,0};
            if (m==2)return {0,1};
            if (m==3)return {1,1};
            if (m==4)return {1,0};
      }

      ll sq = (n/2)*(n/2);
      ll tm = m/sq , rem = m%sq , cx , cy , orientation = 0;
      if (rem==0)tm-- , rem = sq;

      if (tm==0)cx = 0 , cy = 0 , orientation = -1;
      else if (tm==1)cx = 0 , cy = n/2;
      else if (tm==2)cx = n/2 , cy = n/2;
      else if (tm==3)cx = n-1 , cy = n/2-1 , orientation = 1;

      pair<ll,ll> p = rec(n/2,rem);
      ll x = p.first , y = p.second;

      if (orientation==-1)cx += y, cy+=x;
      else if (orientation==1)cx-=y, cy-=x;
      else cx+=x, cy+=y;

      return {cx,cy};
}

int main()
{
      ll n,m;
      cin >> n >> m;
      /*while(true)
      {
            cin >> n >> m;
            */
            pair<ll,ll> p = rec(n,m);
            cout << p.first+1 << " " << p.second+1 << endl;
      /*
      }*/

      return 0;
}
