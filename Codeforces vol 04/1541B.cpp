#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

ll n;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n);
            vector<pair<ll,ll> > v;
            for (int i=1 ; i<=n ; i++){
                  ll a;
                  scl(a);
                  v.push_back({a,i});
            }

            sort(v.begin(),v.end());

            ll ans = 0;

            for (int i=0 ; i<n ; i++){
                  for (int j=i+1 ; j<n && v[i].first*v[j].first<=2*n ; j++){
                        if (v[i].first*v[j].first == v[i].second+v[j].second)ans++;
                  }
            }
            printf("%lld\n",ans);
      }

      return 0;
}
