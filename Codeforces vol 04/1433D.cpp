#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5] , T[n+5] , a = 1 , b = -1;
            for (int i=1 ; i<=n ; i++){

                  cin >> T[i];
                  if (T[1]!=T[i])b = i;
            }

            if (b==-1)cout << "NO" << endl;
            else {
                  cout << "YES" << endl;
                  cout << 1 << " " << b << endl;

                  for (int i=2 ; i<=n ; i++){
                        if (i==b)continue;

                        if (T[i]!=T[1])cout << 1 << " " << i << endl;
                        else cout << b << " " << i << endl;
                  }
            }
      }

      return 0;
}
