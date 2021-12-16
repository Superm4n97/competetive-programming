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

            ll A[n+5] , cnt[n+5],ans = 0;
            memset(cnt,0,sizeof cnt);
            for (int i=1 ; i<=n ; i++)scl(A[i]);

            for (int i=1 ; i<=n ; i++){
                  ll cal = cnt[i];
                  ll ex = A[i]+cnt[i]-1;
                  if (ex<0)cnt[i+1] += ex;
                  for (int j=2 ; j<=A[i]; j++){
                        if (i+j>n){
                              cal+=(A[i]-j+1);
                              break;
                        }
                        cnt[i+j]--;
                        cal++;
                  }
                  ans += max(0LL,cal);
            }
            printf("%I64d\n",ans);
      }

      return 0;
}
