#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;

            vector<ll> v;
            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }

            ll g1 = v[0] , g2 = v[1];

            for (int i=2 ; i<n ; i++){
                  if (i%2==0)g1 = __gcd(g1,v[i]);
                  else g2 = __gcd(g2,v[i]);
            }

            for (int i=0 ; i<n ; i++){
                  if (i%2==0 && v[i]%g2==0){
                        g2 = -1;
                  }
                  if (i%2==1 && v[i]%g1==0)g1 = -1;
            }
            if (g1!=-1)cout << g1 << endl;
            else if (g2!=-1)cout << g2 << endl;
            else cout << 0 << endl;
      }

      return 0;
}
