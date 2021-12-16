#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll n,q;
      scl(n);
      scl(q);

      ll A[n+5] , cnt = 0;
      for (int i=1 ; i<=n ; i++){
            scl(A[i]);
            if (A[i]==1)cnt++;
      }

      while(q--){
            ll type , x;
            scl(type);
            scl(x);

            if (type==1){
                  A[x] = 1-A[x];
                  if (A[x]==1)cnt++;
                  else cnt--;
            }
            else {
                  if (x<=cnt)printf("1\n");
                  else printf("0\n");
            }
      }

      return 0;
}
