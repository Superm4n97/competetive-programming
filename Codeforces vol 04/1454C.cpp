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

            ll A[n+5] , mp[n+5] , fst , lst;
            memset(mp,0,sizeof mp);

            for (int i=1;  i<=n ; i++)cin >> A[i];

            fst=A[1];
            lst = A[n];
            mp[A[1]]++;

            for (int i=2 ; i<=n ; i++){

                  if (A[i]!=A[i-1]){
                        mp[A[i]]++;
                  }
            }

            ll ans = n+5;

            for (int i=1 ; i<=n ; i++){

                  ll temp = mp[A[i]]-1;
                  if (fst!=A[i])temp++;
                  if (lst!=A[i])temp++;
                  ans = min(ans,temp);
            }
            cout << ans << endl;
      }

      return 0;
}
