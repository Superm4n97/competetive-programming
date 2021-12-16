#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      string s;
      cin >> s;

      ll n = s.size();

      cout << "3" << endl;
      cout << "R 2" << endl;
      cout << "L " << n << endl;
      cout << "L " << n-1 << endl;

      return 0;
}
