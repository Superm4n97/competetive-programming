#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll a,b,c;
            cin >> a >> b >> c;
            if ((a+b+c)%9)cout << "NO" << endl;
            else {
                  ll temp = (a+b+c)/9;
                  if (a<temp || b<temp || c<temp)cout << "NO" << endl;
                  else cout << "YES" << endl;
            }
      }


      return 0;
}
