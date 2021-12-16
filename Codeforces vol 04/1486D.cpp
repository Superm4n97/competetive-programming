#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

int n,k,A[maxn],cnt[maxn],mx[maxn] , ans = 0;

int main()
{
      scanf("%d %d",&n,&k);
      for (int i=1 ; i<=n ; i++)scanf("%d",&A[i]);

      int b = 1 , e = n;
      while(b<=e){
            int mid = (b+e)/2;

            for (int i=1 ; i<=n ; i++){
                  if (A[i]>=mid)cnt[i] = cnt[i-1]+1;
                  else cnt[i] = cnt[i-1]-1;
            }
            mx[n] = cnt[n];
            for (int i=n-1 ; i>=1 ; i--)mx[i] = max(mx[i+1],cnt[i]);

            bool sol = false;

            for (int i=1 ; i<=n ; i++){
                  if (i+k-1>n)break;
                  if (mx[i+k-1]>cnt[i-1])sol = true;
            }
            if (sol){
                  ans = max(ans,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }

      printf("%d\n",ans);

      return 0;
}
/**
13 6
1 2 1 4 5 1 2 1 2 4 5 1 2

13 5
1 2 1 4 5 1 3 1 2 4 5 1 2
**/
