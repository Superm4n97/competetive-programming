#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            scl(n);

            ll a[n+5] , b[n+5] , c[n+5];
            for (int i=1 ; i<=n ; i++)scl(c[i]);
            for (int i=1 ; i<=n ; i++)scl(a[i]);
            for (int i=1 ; i<=n ; i++)scl(b[i]);

            ll cycle , ans = 0;

            for (int i=2 ; i<=n ; i++){
                  if (a[i]>b[i])swap(a[i],b[i]);
                  if (i==2){
                        cycle = b[i] - a[i] +1 + c[i];
//                        show(cycle);
                        ans = max(ans,cycle);
                        continue;
                  }
                  if (a[i]==b[i])cycle = c[i]+1;
                  else {
                        cycle = max(cycle - (b[i]-a[i]-1) + c[i] , b[i]-a[i]+c[i]+1);
                  }
                  ans = max(ans,cycle);
                  //show(cycle);
            }
            printf("%I64d\n",ans);
      }


      return 0;
}
