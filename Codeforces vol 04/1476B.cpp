#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n,k;
            scl(n), scl(k);

            ll A[n+5] , s = 0, extra = 0;
            for (int i=0 ; i<n ; i++){
                  scl(A[i]);
                  s+=A[i];
            }

            for (int i=n-1 ; i>0 ; i--){
                  s-=A[i];
//                  show(s);
                  if (A[i]*100 > k*s){
                        ll temp = (A[i]*100 - k*s);
                        temp = (temp+k-1)/k;
                        extra+=temp;
                        s+=temp;
                  }
            }
            printf("%I64d\n",extra);
      }


      return 0;
}

