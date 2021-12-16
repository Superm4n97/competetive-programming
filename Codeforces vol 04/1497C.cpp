#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll solve(ll n, ll k)
{
      if (n%2==0){
            if (n%4)printf("2 %lld %lld\n",n/2-1 , n/2-1);
            else printf("%lld %lld %lld\n",n/4 ,n/4 , n/2);
      }
      else {
            printf("1 %lld %lld\n",n/2,n/2);
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n,k;
            scanf("%lld %lld",&n,&k);
            for (ll i = 4 ; i<=k ; i++){
                  printf("1 ");
                  n--;
            }
            solve(n,3);
      }


      return 0;
}
