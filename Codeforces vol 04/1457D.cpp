#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      scanf("%I64d",&n);

      ll A[n+5];

      for (int i=1 ; i<=n ; i++){
            scanf("%I64d",&A[i]);
      }

      if (n==2){
            cout << -1 << "\n";
            return 0;
      }

      ll ans = 5;
      for (int i=2 ; i<n ; i++)
      {
            ll x = A[i]^A[i+1];
            if (x<A[i-1])ans = 1;
            x = A[i]^A[i-1];
            if (x>A[i+1])ans = 1;
      }

      if (ans==1){
            cout << 1 << "\n";
            return 0;
      }

      if (n==3){
            cout << -1 << "\n";
            return 0;
      }
      for (int i=2 ; i<n-1 ; i++){

            ll x = A[i] ^ A[i+1] ^ A[i+2];
            if (x<A[i-1])ans = min(ans,2LL);

            x = A[i-1] ^ A[i];
            ll y = A[i+1] ^ A[i+2];
            if (x>y)ans = min(ans,2LL);

            x = A[i-1] ^ A[i] ^ A[i+1];
            if (x>A[i+2])ans = min(ans,2LL);

      }

      if (ans>2)ans = -1;

      cout << ans << "\n";

      return 0;
}
