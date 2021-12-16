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

            if (n==1)cout << 9 << endl;
            else if (n==2)cout << 98 << endl;
            else {
                  cout << 989;
                  for (int i=0 ; i<=n-4 ; i++)cout << (i%10);
                  cout << endl;
            }

            ll temp = 9;
      }

      return 0;
}
