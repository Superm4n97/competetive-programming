#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;
      vector < ll > v;

      for (int i=0 ; i<n ; i++){
            ll a;
            cin  >> a;
            v.push_back(a);
      }

      sort(v.begin() , v.end());

      cout << min(v[n-1]-v[1] , v[n-2]-v[0]) << endl;


      return 0;
}
