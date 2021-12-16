#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,x;
            cin >> n >> x;

            if (n<=2)cout << 1 << endl;
            else {
                  ll temp = n-2;
                  temp = (temp+x-1)/x;

                  cout << temp+1 << endl;
            }
      }


      return 0;
}

