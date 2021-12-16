#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll v, t, s, d;
      cin >> v >> t >> s >> d;
      if (d>=t*v && d<=s*v)cout << "No" << endl;
      else cout << "Yes" << endl;

      return 0;
}
