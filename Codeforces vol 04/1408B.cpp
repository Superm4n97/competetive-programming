#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      scanf("%I64d",&tc);

      //show(tc);
      while(tc--){

            ll n,k;
            scanf("%I64d %I64d",&n,&k);

            ll A[n+5],B[105][105];
            memset(B,0,sizeof B);


            ll ans = 105;
            ll temp = 0 , cnt = 0;

            for (int i=1 ; i<=n ; i++){
                  scanf("%I64d",&A[i]);
                  B[1][i] = A[i];
            }

            if (A[1]!=A[n] && k==1){
                  cout << -1 << endl;
                  continue;
            }

            for (int i=1 ; i<=102 ; i++){
                  temp = 0 , cnt = 1;
                  ll bk = 0;

                  for (int j=2 ; j<=n ; j++){
                        if(B[i][j] != B[i][j-1]){
                              cnt++;
                              if (cnt==k)temp = B[i][j-1];
                        }

                        if (cnt>k){
                              B[i+1][j] = B[i][j] - temp;
                              bk = 1;
                        }
                  }

                  ans = i;

                  if (!bk)break;
            }

            printf("%I64d\n",ans);
      }

      return 0;
}
