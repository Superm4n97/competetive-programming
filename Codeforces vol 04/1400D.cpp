#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll csum[3005][3005] , A[3005];

ll calculation(ll id, ll l , ll r)
{
      return csum[id][r] - csum[id][l-1];
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            for (int i=0 ; i<=n+3 ; i++)
                  for (int j=0; j<=n+3; j++)csum[i][j] = 0;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  csum[A[i]][i] = 1;
            }

            for (int i=1 ; i<=n+2 ; i++)
                  for (int j=1 ; j<=n+2 ; j++)csum[i][j] += csum[i][j-1];

            ll ans = 0;

            for (ll i=1 ; i<=n ; i++){
                  for (ll j=i+1 ; j<=n ; j++){
                        ans+=(calculation(A[j],1,i-1)*calculation(A[i],j+1,n));
                  }
            }

            cout << ans << endl;
      }

      return 0;
}
