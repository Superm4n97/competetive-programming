#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%lld",&w)
#define show(x)         cout << #x << " : " << x << endl
#define inf             100000000000000017
#define maxn            1000006

using namespace std;


int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n,a,b;
            cin >> n ;
            a= n/3 , b = n/3;
            if (n%3==1)a++;
            if (n%3==2)b++;

            cout << a << " " << b << endl;
      }

      return 0;
}

/**

*/
