#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            cin >> n;
            vector <ll> v;
            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }
            sort(v.begin(),v.end());

            ll ans = n+5;

            for (int i=0 ; i<n ; i++){
                  ll l = v[i]-1-i , r = 2*n-v[i]-(n-i-1);
                  ans = min(ans,max(l,r));
            }
            cout << ans << endl;
      }


      return 0;
}
