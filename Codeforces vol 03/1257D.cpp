#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll solve()
{
      ll n;
      cin >> n;

      ll A[n+5] , mx = -1;

      for (int i=1 ; i<=n ; i++){
            cin >> A[i];
            mx = max(mx,A[i]);
      }

      ll m;
      cin >> m;

      vector < pair < ll , ll > > _hero , hero;

      for (int i=1 ; i<=m ; i++){
            ll a , b;
            cin >> a >> b;
            _hero.push_back({a,b});
      }

      sort(_hero.begin() , _hero.end());

      hero.push_back(_hero[_hero.size()-1]);

      for (int i=_hero.size()-2 ; i>=0 ; i--){
            if (_hero[i].second<=_hero[i+1].second){
                  _hero[i].second = _hero[i+1].second;
            }
            else {
                  hero.push_back({_hero[i]});
            }
      }

      if (hero[0].first<mx){
            cout << -1 << endl;
      }
      else {
            ll id = 1 , ans = 0;

            //show(hero.size());

            while(id<=n){

                  ans++;

                  ll pre = 0 , localmx = A[id] , fx = id;
                  for (int i=0 ; i<hero.size() ; i++){

                        if (hero[i].first<localmx)break;

                        ll cnt;
                        if (i==0)cnt = hero[i].second;
                        else cnt = hero[i].second+fx-id;
                        if (cnt<=0 || id>n)break;

                        while(A[id]<=hero[i].first && cnt>0 & id<=n){
                              cnt--;
                              id++;
                              if (id>n)break;
                              localmx = max(localmx,A[id]);
                        }
                  }
            }
            cout << ans << endl;
      }
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--)solve();


      return 0;
}
