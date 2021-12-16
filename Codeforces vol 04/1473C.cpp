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
            ll n , k;
            scl(n),scl(k);

            ll lim = 2*k-n-1;

            for (ll i=1 ; i<=lim ; i++){
                  printf("%I64d ",i);
            }
            for (ll i=k ; i>lim ; i--)printf("%I64d ",i);
            printf("\n");
      }

      return 0;
}
