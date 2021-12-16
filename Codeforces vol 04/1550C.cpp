#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005
#define inf 100000000000000000
#define scl(x) scanf("%lld",&x)

using namespace std;

ll S[4*maxn] , M[4*maxn];
ll A[maxn] , n;


int main()
{
      ll tc;
      scl(tc);
      while(tc--){
            scl(n);
            for (int i=1 ; i<=n ; i++)scl(A[i]);
            //build(1,1,e);
            ll l = 1 , ans = 0;
            for (int i=1 ; i<=n ; i++){
                  ll temp = min(i,2);
                  if (i>2){
                        if (A[i]>=A[i-1] && A[i-1]>=A[i-2]){

                        }
                        else if (A[i]<=A[i-1] && A[i-1]<=A[i-2]){

                        }
                        else temp = 3;
                  }
                  if (i>3){
                        if (A[i]<=A[i-1] && A[i-1]<=max(A[i-2],A[i-3])){

                        }
                        else if (A[i]>=A[i-1] && A[i-1]>=min(A[i-2],A[i-3])){

                        }
                        else if (A[i-3]>=A[i-2] && A[i-2]>=min(A[i],A[i-1])){

                        }
                        else if (A[i-3]<=A[i-2] && A[i-2]<=max(A[i],A[i-1])){

                        }
                        else temp = 4;
                  }
                  ans+=temp;
            }
            printf("%lld\n",ans);
      }

      return 0;
}
