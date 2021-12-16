#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;
/**
a^m = x mod m
a^np-q = x
a^np = x*a^q
**/

ll n = sqrt(100000007)+1 , mod = 100000007;

ll amodb(ll a, ll b)
{
      return a - (a/b * b);
}

ll bigmod(ll a, ll p, ll md)
{
      if (p==0)return 1;
      ll temp = bigmod(a,p/2,md);
      temp = amodb(temp*temp,mod);
      if (p%2)temp = amodb(temp*a,mod);///
      return temp;
}

/**
3 9
3^10001-9999 = 9
3^10001  =  9*3^9999
16718546    50466907
33172344
**/
ll BSGS(ll a, ll x)
{
      unordered_map<ll,ll> mp;

      for (ll i=0 ; i<n ; i++){
            ll temp = amodb(bigmod(a,i,mod)*x,mod);
            mp[temp] = i+1;
      }
      for (ll i = 0 ; i<=n ; i++){
            ll temp = bigmod(a,n*i,mod);
            if (mp[temp]!=0){
                  ll p = i , q = mp[temp]-1 , ret = amodb(p*n-q+mod,mod);
                  return ret;
            }
      }
      return -1;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc; _t++){

            ll k,x;
            scanf("%lld %lld",&k,&x);
            ll ans = BSGS(k,x);
            if (ans == -1){
                  printf("-1\n");
            }
            else {
                  printf("Case %d: %lld\n",_t,ans);
            }
      }

      return 0;
}
