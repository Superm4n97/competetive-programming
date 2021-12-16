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
            ll t[n+5] , x[n+5] , tr = 0 , tl = 0 , xl = 0 , xr = 0 , ans = 0;
            for (int i=1 ; i<=n ; i++){
                  scl(t[i]);
                  scl(x[i]);
            }
            t[n+1] = 100000000000014;

            for (int i=1 ; i<=n  ; i++){
                  if (tr<=t[i]){
                        xl = xr;
                        xr = x[i];
                        tl = t[i];
                        tr = tl+abs(xr-xl);
                  }

                  if (xr>=xl){//incremental
                        ll temp = t[i]-tl;
                        tl+=temp;
                        xl+=temp;
                        xl = min(xl,xr);

                        ll L = xl, R = xl+t[i+1]-t[i];
                        R = min(R,xr);

                        if (x[i]>=L && x[i]<=R){
                              ans++;
                        }
                  }
                  else {
                        ll temp = t[i]-tl;
                        tl+=temp;
                        xl-=temp;
                        xl = max(xl,xr);

                        ll L = xl, R = xl - t[i+1]+t[i];
                        R = max(R,xr);

                        if (L>=x[i] && R<=x[i]){
                              ans++;
                        }
                  }
            }
            printf("%I64d\n",ans);
      }


      return 0;
}
