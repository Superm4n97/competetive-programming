#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){

            ll n , mx = 0;
            cin >> n;
            ll A[n+5];

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  mx = max(mx,A[i]);
            }

            ll ans = -1;

            for (int i=1 ; i<=n ; i++){
                  if (A[i]==mx){

                        if (i>1 && A[i]>A[i-1])ans = i;
                        if (i<n && A[i]>A[i+1])ans = i;
                  }
            }

            cout << ans << endl;
      }

      return 0;
}
