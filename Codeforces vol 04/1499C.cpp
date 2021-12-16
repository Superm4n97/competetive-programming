#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);
      while(tc--){

            ll n;
            scanf("%I64d",&n);

            ll A[n+5] ;
            for (int i=1 ; i<=n ; i++)scanf("%I64d",&A[i]);

            ll currX = A[1] , quatityX = n , currY = A[2] , quatityY = n;
            ll sumX = currX*quatityX , sumY = currY*quatityY;
            ll ans = sumX+sumY;
            for (int i=3 ; i<=n ; i++){
                  if (i&1){
                        if (currX>A[i]){
                              sumX -= (quatityX*currX);
                              sumX+=currX;
                              quatityX--;
                              sumX += quatityX*A[i];
                              currX = A[i];
                        }
                        else {
                              sumX -= currX;
                              quatityX--;
                              sumX+=A[i];
                        }
                  }
                  else {
                        if (currY>A[i]){
                              sumY -= (quatityY*currY);
                              sumY+=currY;
                              quatityY--;
                              sumY += quatityY*A[i];
                              currY = A[i];
                        }
                        else {
                              sumY -= currY;
                              quatityY--;
                              sumY+=A[i];
                        }
                  }
                  ans = min(ans,sumX+sumY);
            }
            printf("%I64d\n",ans);
      }

      return 0;
}
