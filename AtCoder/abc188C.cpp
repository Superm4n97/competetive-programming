#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll p;
      scl(p);

      ll n = 1;
      for (int i=0 ; i<p ; i++)n*=2;

      ll A[n+5] , mid = n/2;

      for (int i = 1;  i<=n ; i++)scl(A[i]);

      ll mx1 = 0 , id1=0 , mx2 = 0 ,id2 = 0;

      for (int i=1 ; i<=mid ; i++){
            if (A[i]>mx1){
                  mx1 = A[i];
                  id1 = i;
            }
      }
      for (int i=mid+1 ; i<=n; i++){
            if (A[i]>mx2){
                  mx2 = A[i];
                  id2 = i;
            }
      }

      if (mx1<mx2)printf("%lld\n",id1);
      else printf("%lld\n",id2);


      return 0;
}
