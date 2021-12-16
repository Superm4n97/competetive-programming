#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
vector < pair < pair < ll , ll > , pair < ll , ll > > > vp , v;
stack < pair < pair < ll , ll > , pair < ll , ll > > > st;

vector < pair < ll ,ll > > ans;

int main()
{
      cin >> n;
      for (ll i=1 ; i<=n ; i++){
            ll x,y,z;
            cin >> x >> y >> z;
            vp.push_back({{x,y},{z,i}});
      }
      sort(vp.begin(),vp.end());

      v.push_back(vp[0]);

      for (int i=0 ; i<n ; i++){

            if (st.empty()){
                  st.push(vp[i]);
                  continue;
            }

            ll x = vp[i].first.first;
            st.push(vp[i]);

            while(vp[i+1].first.first == x && i+1<n){
                  st.push(vp[i+1]);
                  i++;
            }

            while(st.size()>=2){
                  ll id1 = st.top().second.second;
                  st.pop();
                  ll id2 = st.top().second.second;
                  st.pop();
                  ans.push_back({id1,id2});
            }
      }

      for (int i=0 ; i<ans.size() ; i++)cout << ans[i].first << " " << ans[i].second << endl;



      return 0;
}
