#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 1000000000012

using namespace std;

ll n , ans = 0;
vector < ll > v;

int main()
{
      cin >> n;

      for (int i=0 ; i<n; i++){

            ll a;
            cin >> a;
            if (a<0)a = -a;

            v.push_back(a);
      }

      v.push_back(inf);
      sort(v.begin() , v.end());

      ll j = 0;
      for (int i=0 ; i<n ; i++){

            while(v[j+1]<=v[i]*2)j++;

            ans += j-i;
      }

      cout << ans << endl;


      return 0;
}
