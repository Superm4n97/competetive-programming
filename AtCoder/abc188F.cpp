#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

unordered_map<ll,ll> mp;
ll x,y;

ll rec(ll a)
{
      if (a<x)return x-a;
      if (x==a)return 0;

      if (mp[a]!=0)return mp[a];

      ll ret = a-x;
      if (a&1){
            ret = min(ret,rec(a+1)+1);
            ret = min(ret,rec(a-1)+1);
      }
      else ret = min(ret,rec(a/2)+1);
      return mp[a] = ret;
}

int main()
{
      scl(x),scl(y);

      printf("%lld\n",rec(y));

      return 0;
}
