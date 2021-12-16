#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){

            ll n,k;
            cin >> n >> k;

            vector < ll > v;
            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;

                  v.push_back(a);
            }

            sort(v.rbegin(),v.rend());

            ll ans = v[0];

            for (int i=1 ; i<min(n,k+1) ; i++){
                  ans+=v[i];
            }

            cout << ans << endl;
      }

      return 0;
}
