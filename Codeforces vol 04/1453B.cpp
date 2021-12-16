#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5];

            for (int i=1 ; i<=n ; i++)cin >> A[i];

            ll X = 0;
            for (int i=2 ; i<=n ; i++)X+=abs(A[i-1]-A[i]);

            ll ans = X;

            for (int i=2 ; i<n ; i++){
                  if ((A[i]>A[i-1]&& A[i]>A[i+1]) || (A[i]<A[i-1] && A[i]<A[i+1]))
                        ans = min(ans,X-abs(A[i]-A[i-1])-abs(A[i]-A[i+1])+abs(A[i-1]-A[i+1]));
            }
            ans = min(min(ans,X-abs(A[n]-A[n-1])),X-abs(A[1]-A[2]));
            cout << ans << endl;
      }

      return 0;
}
