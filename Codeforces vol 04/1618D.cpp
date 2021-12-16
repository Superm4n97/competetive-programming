#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n , k;
vector<pair<ll,ll> >vp;
ll dp[105][55];

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            cin >> n >> k;
            memset(dp,-1,sizeof dp);

            vector<ll>v , v_new;
            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }

            sort(v.rbegin(),v.rend());
            ll ans = 0;

            for (int i=0 ; i<k ; i++){
                  ll j = i+k;
                  if (v[i]==v[j])ans++;
            }
            for (int i=2*k ; i<n ; i++)ans+=v[i];

            cout << ans << endl;
      }

      return 0;
}
