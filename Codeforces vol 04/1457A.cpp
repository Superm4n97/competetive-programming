#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll tme(ll a, ll b, ll c, ll d)
{
      return abs(a-c)+abs(b-d);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){

            ll n,m,x,y;
            cin >> n >> m >> x >> y;
            cout << max(max(tme(1,1,x,y),tme(n,1,x,y)),max(tme(1,m,x,y),tme(n,m,x,y))) << endl;
      }

      return 0;
}
