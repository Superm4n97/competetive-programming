#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,m;
            cin >> n >> m;

            bool sol = false;

            for (int i=0 ; i<n ; i++){
                  ll a, b, c, d;
                  cin >> a >> b >> c >> d;

                  if (b==c)sol = true;
            }

            if (m%2==1)cout << "NO" << endl;
            else if (sol)cout << "YES" << endl;
            else cout << "NO" << endl;
      }


      return 0;
}

