#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll a, b;
            string s;
            cin >>a >> b;
            cin >> s;

            vector <pair<ll,ll> > vp;

            s = "0"+s+"0";
            ll str;
            for (ll i=1 ; i<s.size() ; i++){
                  if (s[i-1]=='0' && s[i]=='1')str = i;
                  if (s[i-1]=='1' && s[i]=='0'){
                        vp.push_back({str,i-1});
                  }
            }

            if (vp.empty()){
                  cout << 0 << endl;
                  continue;
            }

            ll ans = a;

            for (int i = 1 ; i<vp.size() ; i++){
                  if ((vp[i].first-vp[i-1].second-1)*b<a)ans+=(vp[i].first-vp[i-1].second-1)*b;
                  else ans+=a;
            }

            cout << ans << endl;
      }

      return 0;
}
