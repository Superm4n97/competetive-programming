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

            ll ans = n , times = 1 , x = n;

            for (ll i=2 ; i*i<=n ; i++){

                  ll cnt = 0 ;
                  while(x%i==0){
                        cnt++;
                        x/=i;
                  }

                  if (cnt>times){
                        times = cnt;
                        ans = i;
                  }
            }

            cout << times << "\n";
            for (int i=1 ; i<times ; i++){
                  cout << ans << " ";
                  n/=ans;
            }
            cout << n << "\n";
      }

      return 0;
}
