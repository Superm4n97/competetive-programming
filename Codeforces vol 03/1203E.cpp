#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc =1;
      //cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            vector < ll > v;

            for (int i=1 ; i<=n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }

            sort(v.begin(),v.end());

            ll mp[150005] , cnt = 0;
            memset(mp,0,sizeof mp);

            mp[0] = 1;

            for (int i = 0; i<n ; i++){

                  if (mp[v[i]-1]==0){
                        mp[v[i]-1] = 1;
                        cnt++;
                  }
                  else if (mp[v[i]]==0){
                        mp[v[i]] = 1;
                        cnt++;
                  }
                  else if(mp[v[i]+1]==0){
                        mp[v[i]+1] = 1;
                        cnt++;
                  }
            }
            cout << cnt << endl;
      }


      return 0;
}
