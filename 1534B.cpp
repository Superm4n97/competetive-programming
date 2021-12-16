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
            scanf("%lld",&n);
            ll A[n+5] , sum = 0;
            memset(A,0,sizeof A);

            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  sum+=abs(A[i]-A[i-1]);
                  if (i==n)sum+=A[i];
            }
            for (int i=1 ; i<=n ; i++){
                  if (A[i]>A[i-1] && A[i]>A[i+1]){
                        ll h = A[i] - max(A[i-1],A[i+1]);
                        sum+=h;
                        sum-=(h*2);
                  }
            }
            printf("%lld\n",sum);
      }

      return 0;
}
