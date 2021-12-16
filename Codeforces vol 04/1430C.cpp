#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){

            ll n;
            cin >> n;

            ll ans = n;
            vector < pair < ll,ll > > vp;

            for (int i=n-1 ; i>=1 ; i--){
                  vp.push_back({ans , i});
                  ans = (i+ans+1)/2;
            }

            cout << ans << endl;
            for (int i=0 ; i<vp.size() ; i++){
                  cout << vp[i].first << " " << vp[i].second << endl;
            }

      }

      return 0;
}
