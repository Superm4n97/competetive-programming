#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll a = 1 , b = 1;

      if ((n-2)%3==0)b = 2;

      cout << a << " " << b << " " << n-a-b << endl;

      return 0;
}

/**

**/
