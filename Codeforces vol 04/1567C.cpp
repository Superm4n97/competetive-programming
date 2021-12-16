#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll x, y;

ll make_digit(vector<ll> v)
{
      ll ret = 0;
      for (int i=v.size()-1 ; i>=0 ; i--){
            ret = ret*10 + v[i];
      }
      return ret;
}

void split(ll n)
{
      vector<ll> a,b;
      ll id = 0;
      while(n){
            if (id&1)a.push_back(n%10);
            else b.push_back(n%10);
            n/=10;
            id++;
      }
      x = make_digit(a);
      y = make_digit(b);

      return;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll a;
            cin >> a;
            split(a);

            cout << (x+1)*(y+1) -2 << endl;
      }

      return 0;
}
