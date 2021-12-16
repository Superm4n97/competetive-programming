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

            ll x[n+5] , y[n+5] , sumX = 0,sumY = 0;
            for (int i=0 ; i<n ; i++){
                  scanf("%I64d %I64d",&x[i],&y[i]);
            }

            ll cnt[n+5] , ans = 0  , counter = -1;
            memset(cnt,0,sizeof cnt);
//            memset(cnty,0,sizeof cnty);

            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<n ; j++){
                        if (x[i]==x[j])cnt[j]++;
                        if (y[i]==y[j])cnt[j]++;
                  }
            }

            for (int i=0 ; i<n ; i++){
                  if (cnt[i]>counter){
                        counter =  cnt[i];
                        ans = 1;
                  }
                  else if (cnt[i]==counter)ans++;
            }

            cout << ans << endl;

      }


      return 0;
}
