#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            scl(n);

            ll x[n+5] , y[n+5];
            for (int i=1 ; i<=n ; i++)scl(x[i]);
            memset(y,0,sizeof y);

            for (ll b = 0 ; b <=32 ; b++){
                  ll pre = 0;
                  if ((x[1]&(1LL<<b)) != 0)pre = 1;

//                  show(b);
//                  show(pre);

                  for (ll i=2 ; i<=n ; i++){
                        if ((x[i]&(1LL<<b)) != 0){//1
                              pre = 1;
                        }
                        else {//0
                              if (pre==1){
                                    y[i] += (1LL<<b);
//                                    show(i);
                              }
                        }
                  }
//                  cout << endl;
            }
            for (int i=1 ; i<=n ; i++)printf("%lld ",y[i]);
            printf("\n");
      }


      return 0;
}
