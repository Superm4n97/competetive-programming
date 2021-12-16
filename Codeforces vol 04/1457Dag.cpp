#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005
#define inf 10000000000000016

using namespace std;

ll sum[maxn] , res = -1 ,A[maxn] , n;

int main()
{
      scanf("%I64d",&n);


      for (int i=1 ; i<=n ; i++){
            scanf("%I64d",&A[i]);
            if (i==1)sum[i] = A[i];
            else sum[i] = sum[i-1] ^ A[i];
      }

      if (n==2){
            cout << -1 << "\n";
            return 0;
      }

      for (int d = 3 ; d<=n ; d++){

            bool solution = false;
            for (int x = 1 , y = d ; y<=n ; x++,y++){
                  for (int i = x ; i<y ; i++){
                        if ((sum[i]^sum[x-1])>(sum[y]^sum[i])){
                              solution = true;
                              break;
                        }
                  }
                  if (solution)break;
            }
            if (solution){
                  res = d-2;
                  break;
            }
      }

      cout << res << "\n";

      return 0;
}
