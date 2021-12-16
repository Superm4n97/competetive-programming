#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll a,b,c,d;
      cin >> a >> b >> c >> d;
      cout << min(min(a,b),min(d,c)) << endl;

      return 0;
}
