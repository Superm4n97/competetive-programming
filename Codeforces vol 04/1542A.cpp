#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout<< #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;
            ll e = 0 , o = 0;
            for (int i=0 ; i<2*n ; i++){
                  ll a;
                  cin >> a;
                  if (a&1LL)o++;
                  else e++;
            }
            if (e==o)cout << "Yes" << endl;
            else cout << "No" << endl;
      }

      return 0;
}
