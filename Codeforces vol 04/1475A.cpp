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
            ll n;
            scl(n);

            while(n%2==0)n/=2;
            cout << (n==1?"NO":"YES") << endl;
      }

      return 0;
}
