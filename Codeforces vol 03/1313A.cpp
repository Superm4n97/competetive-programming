#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc = 1;
      cin >> tc;

      while(tc--){
            ll a,b,c,cnt = 0;
            vector < ll > v;

            for (int i=0 ; i<3; i++){
                  ll x;
                  cin >> x;
                  v.push_back(x);
            }

            sort(v.rbegin(),v.rend());

            a = v[0], b = v[1] , c = v[2];

            if (a)a-- , cnt++;
            if (b)b-- , cnt++;
            if (c)c-- , cnt++;

            if (a&&b)a--,b-- , cnt++;
            if (a&&c)a--,c-- , cnt++;
            if (b&&c)b--,c-- , cnt++;

            if (a&&b&&c)cnt++;

            cout << cnt << endl;
      }

      return 0;
}
