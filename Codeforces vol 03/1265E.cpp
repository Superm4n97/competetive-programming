#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 998244353
#define maxn 200005

using namespace std;

ll A[maxn] , n , inv100;

ll normal(ll a)
{
      ll temp = a/mod;
      return a - temp*mod;
}

ll bigmod(ll a , ll p)
{
      if (p==0)return 1;
      if (p==1)return normal(a);

      ll temp = bigmod(a,p/2);
      temp = normal(temp*temp);

      if (p%2)temp = normal(temp*a);

      return temp;
}

ll inv(ll a)
{
      return bigmod(a,mod-2);
}

pair<ll,ll> rec(ll pos)
{
      ll a = normal(A[pos]*inv100) , b = normal((100-A[pos])*inv100);

      if (pos==n){
            //show(b);
            //show(A[pos]);
            return {1,b};
      }

      pair<ll,ll> p = rec(pos+1);

      p.first++;
      p.first = normal(p.first*a);
      p.first = normal(p.first+b);

      p.second = normal(p.second*a);
      p.second = normal(p.second+b);

      return p;
}

int main()
{
      cin >> n;
      for (int i=1; i<=n ; i++)cin >> A[i];

      inv100 = inv(100);
      //show(normal(50*inv100));

      pair<ll,ll> p = rec(1);
      ll a = p.first , b = p.second;
      ll x = normal(1+mod-b);

      cout << normal(a*inv(x)) << endl;

      return 0;
}
