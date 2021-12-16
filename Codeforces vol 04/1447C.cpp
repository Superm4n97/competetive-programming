#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n , w;
            cin >> n >>  w;

            vector < pair <ll,ll > > vp;

            for (ll i=1 ; i<=n; i++){

                  ll a;
                  cin >> a;
                  if (a<=w){
                        vp.push_back({a,i});
                  }
            }

            sort(vp.rbegin(),vp.rend());

            ll sum = 0;
            vector < ll > ans;

            for (int i=0 ; i<vp.size() ; i++){

                  if (sum+vp[i].first<=w){
                        sum+=vp[i].first;
                        ans.push_back(vp[i].second);
                  }
            }

            ll lim = (w+1)/2;

            if (sum<lim)cout << -1 << endl;
            else {
                  cout << ans.size() << "\n";
                  for (int i=0 ; i<ans.size() ; i++)cout << ans[i] << " ";
                  cout << "\n";
            }
      }

      return 0;
}
