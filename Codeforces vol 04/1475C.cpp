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
            ll a,b,k;
            scl(a),scl(b),scl(k);

            ll freA[a+5] , freB[b+5] , A[a+5] , B[b+5];
            memset(freA,0,sizeof freA);
            memset(freB,0,sizeof freB);

            for (int i=0 ; i<k ; i++){
                  scl(A[i]);
                  freA[A[i]]++;
            }
            for (int i=0 ; i<k ; i++){
                  scl(B[i]);
                  freB[B[i]]++;
            }

            ll ans = 0;

            for (int i=0 ; i<k ; i++){
                  ll x = freA[A[i]]-1 , y = freB[B[i]]-1;
                  ans+=(k-1-x-y);
            }
            printf("%I64d\n",ans/2);
      }

      return 0;
}
