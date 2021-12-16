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
            cin >> a;
            v.push_back(a);
      }

      sort(v.begin() , v.end());

      cout << v[n-1]-v[0]+1 - n << endl;

      return 0;
}
/**

**/
