#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,d;
      cin >> n>> d;

      ll m;
      cin >> m;

      while(m--){

            ll x,y;
            cin >> x >> y;

            if (y-x<=d && y-x>=-d && x+y>=d && x+y<=n+n-d)cout << "YES" << endl;
            else  cout << "NO" << endl;
      }


      return 0;
}


/**

n,d;
3 6

3 5
3 4
3 3
3 2
3 1

3 0


**/
