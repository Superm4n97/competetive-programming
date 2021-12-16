#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll a,b,c,m;
            cin >> a >> b >> c >> m;
            if (b>a && b>c)swap(a,b);
            if (c>a && c>b)swap(a,c);

            if (a+b+c-3<m)cout << "NO" << endl;
            else {
                  if (a-m-1>b+c)cout << "NO" << endl;
                  else cout << "YES" << endl;
            }
      }


      return 0;
}
