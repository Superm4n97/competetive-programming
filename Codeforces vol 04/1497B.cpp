#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n,m;
            scanf("%lld %lld",&n,&m);

            ll cnt[m+5] , ans = 0;
            memset(cnt,0,sizeof cnt);

            for (int i=1; i<=n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  a%=m;

                  cnt[a]++;
            }

            for (int i=0 ; i<m ; i++){
                  if (cnt[i]==0)continue;
                  ll alter = m - i;

                  if (i==0 || i==alter || abs(cnt[alter]-cnt[i])<=1){
                        ans++;
                        cnt[i] = cnt[alter] = 0;
                  }
                  else {
                        ll temp = abs(cnt[alter]-cnt[i]);
                        ans += temp;
                        cnt[i] = cnt[alter] = 0;
                  }
            }

            printf("%lld\n",ans);
      }


      return 0;
}
