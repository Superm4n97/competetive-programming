#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll a,b;
      cin>> a >> b;
      if (min(a,b)+3>max(a,b))cout << "Yes" << endl;
      else cout << "No" << endl;

      return 0;
}
