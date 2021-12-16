#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll x, y , ans = 0;
            scl(x) , scl(y);
            y = min(y,x-1);

//            show(y);
            for (ll i=1 ;i<y; i++){
                  ll temp = min(y-i,x/i - (i+1));
//                  ll p = temp+i;
//                  show(temp);
                  if (temp<=0)break;
                  ans+=temp;
            }
            printf("%I64d\n",ans);
      }

      return 0;
}
