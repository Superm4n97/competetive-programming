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

            ll sum = 0;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  sum+=a;
            }

            if (sum==m)cout << "YES" << endl;
            else cout << "NO" << endl;
      }


      return 0;
}
