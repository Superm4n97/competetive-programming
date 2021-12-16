#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout<< #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      scanf("%lld",&tc);

      while(tc--){
            ll n,a,b;
            scanf("%lld %lld %lld",&n,&a,&b);

            if (a==1){
                  if ((n-1)%b==0)printf("Yes\n");
                  else printf("No\n");
            }
            else {
                  ll temp = 1, sol = 0;
                  while(temp<=n){
                        if ((n-temp)%b==0)sol = 1;
                        temp*=a;
                  }
                  if (sol)printf("Yes\n");
                  else printf("No\n");
            }
      }


      return 0;
}
