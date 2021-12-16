#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n;
      cin >> n;
      ll e = 0 , o = 0;

      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a;

            if (a%2)o++;
            else e++;
      }

      cout << min(o,e) << endl;

      return 0;
}
