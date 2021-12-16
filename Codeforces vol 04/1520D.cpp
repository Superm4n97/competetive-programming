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
            ll A[n+5];

            map<ll,ll> mp;

            ll ans = 0;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  ll temp = A[i]-i;
                  ans+=mp[temp];
                  mp[temp]++;
            }
            cout << ans << "\n";
      }

      return 0;
}
/*
Aj - Ai = j-i
Aj - j = A[i]-i
*/
