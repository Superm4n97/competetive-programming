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
            cin >> n;

            for (int i=1 ; i<=9 ; i++){

                  ll temp = i;
                  while(temp<=n){

                        if (temp)ans++;
                        temp*=10;
                        temp+=i;
                  }
            }
            cout << ans << endl;
      }


      return 0;
}
