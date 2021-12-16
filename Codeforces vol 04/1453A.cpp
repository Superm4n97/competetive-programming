#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,m;
            cin >> n >> m;
            set <ll> s;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  s.insert(a);
            }
            for (int i=0 ; i<m ; i++){
                  ll a;
                  cin >> a;
                  s.insert(a);
            }
            cout << n+m-s.size() << endl;
      }

      return 0;
}
