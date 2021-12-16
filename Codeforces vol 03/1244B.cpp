#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;
            string s;
            cin >> s;

            ll ans = n;

            for (int i=0 ; i<n ; i++){

                  if (s[i]=='1'){
                        ll lf = i*2 , rg = (n-i-1)*2;
                        ans = min(ans,min(lf,rg));
                  }
            }

            cout << 2*n-ans << endl;
      }


      return 0;
}
