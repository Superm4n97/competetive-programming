#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll l = 0 , r = 0;

      for (int i=0 ; i<n ; i++){

            ll a;
            cin >> a;

            if (a==0)l = i;
            else r = i;
      }

      cout << min(l,r)+1 << endl;

      return 0;
}
