#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(w) scanf("%I64d",&w);

using namespace std;

int main()
{
      ll tc;
      scl(tc);
      while(tc--){

            ll n , sum = 0;
            scl(n);

            ll A[n+5];

            for (int i=1 ; i<=n ; i++){
                  scl(A[i]);
                  sum+=A[i];
            }

            ll ans = n-1;

            for (int j = 2 ; j<=n ; j++){
                  if (sum%j!=0)continue;
                  bool sol = true;

                  ll mid = sum/j, t_sum = 0 ,cnt = 0 ;

                  for (int i = 1 ; i<=n ; i++){
                        if (t_sum<mid){
                              if (t_sum>0)cnt++;
                              t_sum+=A[i];
                        }
                        if (t_sum>mid){
                              sol = false;
                              break;
                        }
                        if (t_sum==mid)t_sum = 0;
                  }

                  if (sol)ans = min(ans,cnt);
            }
            printf("%I64d\n",ans);
      }

      return 0;
}
