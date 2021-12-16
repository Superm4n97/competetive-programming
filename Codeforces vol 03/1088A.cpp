#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll x;
      cin >> x;

      if (x<2)cout << -1 << endl;
      else {
            if (x%2)x--;
            cout << x << " " << 2 << endl;
      }

      return 0;
}
