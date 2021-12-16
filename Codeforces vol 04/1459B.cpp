#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(w) scanf("%I64d",&w)

using namespace std;

int main()
{
      ll n;
      cin >> n;
      if (n%2==0){
            cout << (n/2+1)*(n/2+1) << endl;
      }
      else {
           ll x = (n+2)/2;
           ll y = x+1;
           cout << x*y*2 << endl;
      }

      return 0;
}
