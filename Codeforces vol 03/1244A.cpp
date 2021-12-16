#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll a, b, c, d,k;
            cin >> a >> b >> c >> d >> k;

            ll pen = (a+c-1)/c , pencil = (b+d-1)/d;

            if (pen+pencil<=k){
                  cout << pen << " " << pencil << endl;
            }
            else cout << -1 << endl;
      }


      return 0;
}
