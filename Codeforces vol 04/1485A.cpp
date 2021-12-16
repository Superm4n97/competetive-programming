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

            ll a,b , ans = 10000000000000 , cnt = 0;
            scl(a) , scl(b);
            if (b==1){
                  b++;
                  cnt++;
            }

            ll lg = 1 , c = a;
            while(c){
                  c/=b;
                  lg++;
            }

//            show(lg);

            for (int i=0 ; i<=lg ; i++){
                  c = a;
                  ll mn = i;
                  while(c){
                        c/=b;
                        mn++;
                  }
//                  show(mn);
                  ans = min(ans,mn);
                  b++;
            }
            printf("%I64d\n",cnt+ans);
      }

      return 0;
}
