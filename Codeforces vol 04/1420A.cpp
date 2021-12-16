#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;

            vector < ll > A,B;
            map < ll,ll > mp;

            bool ans = false;

            for (int i=1 ; i<=n ; i++){
                  ll a;
                  cin >> a;
                  A.push_back(a);
                  B.push_back(a);
                  mp[a]++;
                  if (mp[a]>1)ans = true;
            }

            if (ans){
                  cout << "YES" << endl;
                  continue;
            }

            sort(A.rbegin(),A.rend());

            if (A==B)cout << "NO" << endl;
            else cout << "YES" << endl;
      }

      return 0;
}
