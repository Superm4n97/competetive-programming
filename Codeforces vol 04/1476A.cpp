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
            ll n,k;
            scl(n) , scl(k);
            ll temp = (n+k-1)/k  * k;
            cout << (temp+n-1)/n << endl;
      }


      return 0;
}
