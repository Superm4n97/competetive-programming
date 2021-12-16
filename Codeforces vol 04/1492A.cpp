#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll p,a,b,c;

ll res(ll x)
{
      ll temp = p/x;
      if (x*temp==p)return p;
      return (temp+1)*x;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> p >> a >> b >> c;
            cout << min(res(a),min(res(b),res(c)))-p << "\n";
      }

}
