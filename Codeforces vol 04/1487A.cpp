#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n;
            scanf("%I64d",&n);

            ll mn = 10000000000000016 , cnt = 0;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%I64d",&a);
                  if (a==mn)cnt++;
                  if (a<mn){
                        mn = a;
                        cnt = 1;
                  }
            }
            printf("%I64d\n",n-cnt);
      }

      return 0;
}
