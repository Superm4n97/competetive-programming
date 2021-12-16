#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;scl(tc);

      while(tc--){
            ll n,k;
            scl(n), scl(k);

            ll A[n+5];
            for (int i=1 ; i<=n ; i++)scl(A[i]);
            A[n+1] = -1;

            ll ans;

            for (int i=1 ;i<=k; i++){
                  for (int j=1 ; j<=n ; j++){
                        if (A[j]<A[j+1]){
                              A[j]++;
                              ans = j;
                              break;
                        }
                        if (j==n){
                              ans = n+1;
                              break;
                        }
                  }
                  if (ans==n+1)break;
            }
            if (ans==n+1)ans = -1;

            printf("%I64d\n",ans);
      }

      return 0;
}
