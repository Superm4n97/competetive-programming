#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll sum = 0;

      for (int i=0 ; i<n; i++){
            ll a;
            cin >> a;

            sum+=a;
      }

      cout << (sum?"HARD":"EASY") << endl;

      return 0;
}


/**

**/
