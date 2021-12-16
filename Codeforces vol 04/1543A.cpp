#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      scanf("%lld",&tc);
      while(tc--){
            ll a, b;
            scanf("%lld %lld",&a,&b);

            if (a>b)swap(a,b);

            if (a==b){
                  printf("0 0\n");
            }
            else {
                  ll dif = b-a;
                  ll m = a%dif;
                  printf("%lld %lld\n",dif,min(m,dif-m));
            }
      }

      return 0;
}
