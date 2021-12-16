#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 100000000000014

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5] , B[n+5];
            ll b = 0 , e  = -1  ,ans = inf;
            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  e = max(e,A[i]);
            }
            for (int i=1 ; i<=n ; i++)cin >> B[i];

            while(b<=e){

                  ll mid = (b+e)/2;
                  ll sum = 0;
                  for (int i=1 ; i<=n ; i++){
                        if (A[i]>mid){
                              sum+=B[i];
                        }
                  }

                  if (sum<=mid){
                        ans = min(mid,ans);
                        e = mid-1;
                  }
                  else b = mid+1;
            }

            cout << ans << "\n";
      }

      return 0;
}
