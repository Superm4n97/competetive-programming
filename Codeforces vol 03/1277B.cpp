#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n , ans = 0;
            vector < ll > v;
            map < ll , ll > mp;

            cin >> n;

            for (int i=1 ; i<=n; i++){

                  ll a;
                  cin >> a;
                  v.push_back(a);
            }
            sort(v.rbegin(),v.rend());

            for (int i=0 ; i<v.size() ; i++){
                  if (v[i]%2==0){

                        while(true){

                              if (mp[v[i]]==1 || v[i]%2==1)break;

                              mp[v[i]]=1;
                              ans++;
                              v[i]/=2;
                        }
                  }
            }

            cout << ans << endl;
      }


      return 0;
}
