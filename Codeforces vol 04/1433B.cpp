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

            ll lf = n+5 , rg = -1;
            ll A[n+5];
            for (ll i=0 ; i<n ; i++){
                  cin >> A[i];

                  if (A[i]==1){
                        lf = min(lf,i);
                        rg = max(rg,i);
                  }
            }

            ll ans = 0;
            for (int i=lf ; i<=rg ; i++)
            {
                  if (A[i]==0)ans++;
            }

            cout << ans << endl;
      }

      return 0;
}
