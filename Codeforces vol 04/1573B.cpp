#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      scanf("%lld",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);

            ll id[n*2+5],A[n+5],B[n+5];
            memset(id,0,sizeof id);
            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  id[A[i]] = i;
            }
            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&B[i]);
                  id[B[i]] = i;
            }

            for (int i=2*n-2 ; i>=1 ; i--){
                  id[i] = min(id[i],id[i+2]);
            }

            ll ans = n*3;

            for (int i=1 ; i<=n ; i++){
                  ll cnt = i-1;
                  cnt += (id[A[i]+1]-1);
                  ans = min(ans,cnt);
            }

            printf("%lld\n",ans);
      }

      return 0;
}
