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
            cin >> n;
            k = n-1;

            ll A[n+5] , sum = 0 , mx = 0,cnt = 0;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  mx = max(mx,A[i]);
                  sum+=A[i];
            }

            if (sum%k!=0)cnt = (k-(sum%k));

            sum+=cnt;

            mx = max(mx,sum/k);
            cnt+=(mx*k - sum);

            cout << cnt << endl;

      }
}
