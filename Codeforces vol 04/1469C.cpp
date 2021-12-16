#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 200005

using namespace std;

            ll h[maxn] , u[maxn] , d[maxn];
int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n,k;
            scl(n),scl(k);


            for (int i=1 ; i<=n ; i++)scl(h[i]);

            d[1] = h[1];
            u[1] = h[1]+k;

            bool sol = true;

            for (int i=2 ; i<=n ; i++){
                  u[i] = u[i-1]+k-1;
                  d[i] = d[i-1]-k+1;
                  if (d[i]<0)d[i] = 0;
                  ll x = h[i]+ 2*k -1 , y = h[i];
                  if (i==n){
                        x = h[i]+k;
                  }
                  if (x<=d[i-1] || y>=u[i-1]){
                        sol = false;
                  }

                  if (i==n && d[i]>y){
                        sol = false;
                  }
                  u[i] = min(u[i],x);
                  d[i] = max(d[i],y);

            }
            if (sol)printf("YES\n");
            else printf("NO\n");
      }

      return 0;
}
