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

            vector <ll> A,B;
            ll X[n+5] , Y[n+5], ans = n-1;

            for (int i=0 ; i<n ; i++){
                  scanf("%I64d %I64d",&X[i],&Y[i]);
                  A.push_back(X[i]);
                  B.push_back(Y[i]);
            }
            sort(A.begin(),A.end());
            sort(B.begin(),B.end());

            for (int i=0 ; i<n ; i++){

                  ll b = 0 , e = n-1 , res = -1 , outside = 0;
                  while(b<=e){
                        ll mid = (b+e)/2;
                        if (B[mid]<X[i]){
                              res = max(mid , res);
                              b = mid+1;
                        }
                        else e = mid-1;
                  }

                  res++;
                  outside = res;

                  res = n , b = 0 , e = n-1;
                  while(b<=e){
                        ll mid = (b+e)/2;

                        if (A[mid]>Y[i]){
                              res = min(res,mid);
                              e = mid-1;
                        }
                        else b = mid+1;
                  }

                  outside += (n-res);
                  ans = min(ans,outside);
            }

            printf("%I64d\n",ans);
      }
}
