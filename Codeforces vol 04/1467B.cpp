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
            ll n;
            scl(n);

            ll A[n+5] , hill[n+5] , H = 0 , V = 0 , cnt = 0;
            memset(hill,0,sizeof hill);

            for (int i=1 ; i<=n ; i++)scl(A[i]);
            for (int i=2 ; i<n ; i++){
                  if (A[i-1]<A[i] && A[i+1]<A[i]){
                        hill[i] = 1;
                        H++;
                  }
                  if (A[i-1]>A[i] && A[i+1]>A[i]){
                        hill[i] = -1;
                        V++;
                  }
            }
            for (int i=2 ; i<n ; i++){
                  if (hill==0){
                        if (hill[i-1]!=0 || hill[i+1]!=0)cnt = max(cnt,1LL);
                        continue;
                  }

                  if (hill[i]==1){
                        cnt = max(cnt,1LL);
                        if (hill[i+1]==-1 || hill[i-1]==-1)cnt = max(cnt,2LL);
                        if (hill[i+1]==-1 && hill[i-1]==-1)cnt = max(cnt,3LL);
                  }
                  if (hill[i]==-1){
                        cnt = max(cnt,1LL);
                        if (hill[i+1]==1 || hill[i-1]==1)cnt = max(cnt,2LL);
                        if (hill[i+1]==1 && hill[i-1]==1)cnt = max(cnt,3LL);
                  }
            }
            printf("%I64d\n",min(H+V,H+V-cnt));
      }

      return 0;
}
