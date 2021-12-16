#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            vector < ll > v;

            for (int i=0  ;i<n; i ++){
                  ll a;
                  cin >> a;

                  ll cnt = 0;

                  while(a){
                        a/=2;
                        cnt++;
                  }

                  v.push_back(cnt);
            }

            map < ll ,ll > mp;

            for (int i=0 ; i<v.size() ; i++){
                  mp[v[i]]++;
            }

            ll ans = 0;

            for (int i=0 ; i<v.size() ; i++){
                  ans+=(mp[v[i]]*(mp[v[i]]-1)/2);
                  mp[v[i]] = 0;
            }

            cout << ans << endl;
      }

      return 0;
}
