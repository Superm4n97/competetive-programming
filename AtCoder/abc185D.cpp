#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,m;
      cin >> n >> m;

      vector <ll> v;
      vector <pair<ll,ll> > vp;

      for (int i=0 ; i<m ; i++){
            ll a;
            cin >> a ;
            v.push_back(a);
      }
      v.push_back(0LL);
      v.push_back(n+1);
      sort(v.begin(),v.end());

      ll mn = n+5;

      for (int i=0 ; i<v.size()-1 ; i++){
            if (v[i+1]!=v[i]+1){
                  vp.push_back({v[i]+1,v[i+1]-1});
                  mn = min(v[i+1]-1 - (v[i]+1)+1 , mn);
            }
      }
      ll ans = 0;

      //show(mn);

      for (int i=0 ; i<vp.size() ; i++){
            ans += (vp[i].second-vp[i].first+mn)/mn;
      }
      cout << ans << endl;



      return 0;
}
