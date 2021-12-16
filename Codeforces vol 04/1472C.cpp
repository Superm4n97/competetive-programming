#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);
      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5] , ans = 0;
            for (int i=1;  i<=n ; i++)cin >> A[i];
            ans = A[n];
            for (int i=n-1 ; i>=1 ; i--){
                  ll temp = A[i]+i;
                  if (temp<=n)A[i]+=A[temp];
                  ans = max(ans,A[i]);
            }
            cout << ans << endl;
      }

      return 0;
}
