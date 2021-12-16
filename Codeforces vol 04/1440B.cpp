#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,k;
            cin >> n >> k;

            ll A[n*k+5];

            for (int i=1 ; i<=k*n ; i++)cin >> A[i];

            ll temp = (n-1)/2 , ans = 0;

            for (int i=temp*k+1 ; i<=n*k ; i+=(n-temp)){
                  ans+=A[i];
                  //show(i);
            }

            cout << ans << endl;
      }

      return 0;
}
