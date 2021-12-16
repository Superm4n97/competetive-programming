#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << endl

using namespace std;

int main()
{
      ll n , ans = 0;
      cin >> n;
      vector < ll > v;

      for (int i=0 ; i<n ; i++){

            ll a,b;
            cin >> a >> b;

            ans+=(n*b-a);
            v.push_back(a-b);
      }
      sort(v.rbegin() , v.rend());

      for (int i=0 ; i<n; i++){
            ans+=v[i]*(i+1);
      }
      cout << ans << endl;



      return 0;
}
