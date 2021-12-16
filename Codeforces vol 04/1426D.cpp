#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n;
map < ll,ll > mp;
vector < pair < ll,ll > > vp;

int main()
{
      cin >> n;

      ll sum = 0 , pre0 = 0;

      for (ll i=1 ; i<=n ; i++){
            ll a;
            cin >> a;

            sum+=a;

            if (sum==0){
                  vp.push_back({mp[0LL]+1 , i});
                  mp[sum] = i;
                  continue;
            }

            if (mp[sum]!=0){
                  vp.push_back({mp[sum]+1,i});
            }

                  mp[sum] = i;
      }

      if (vp.empty()){
            cout << 0 << endl;
            return 0;
      }

      sort(vp.begin(),vp.end());

      ll ans = 1 , l = vp[0].first , r = vp[0].second;

      for (int i=1 ; i<vp.size() ; i++){

            if (max(vp[i].first,l)>=min(vp[i].second,r)){
                  ans++;
                  l = vp[i].first , r = vp[i].second;
            }
            else {
                  l = max(vp[i].first,l) , r = min(vp[i].second,r);
            }
      }

      cout << ans << endl;


      return 0;
}

