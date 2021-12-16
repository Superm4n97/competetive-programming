#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "  << x << endl
#define mod 100000007
#define maxn 1000099

using namespace std;

ll A[15] , F[maxn] , IN[maxn];

ll amodb(ll a)
{
      return a - a/mod*mod;
}

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;
      ll temp = bigmod(a,p/2);
      temp = amodb(temp*temp);
      if (p&1)temp = amodb(temp*a);
      return temp;
}
ll init()
{
      F[0] = 1;
      for (ll i=1 ; i<maxn ; i++)F[i] = amodb(F[i-1]*i);
      IN[maxn-2] = bigmod(F[maxn-2],mod-2);
      for (ll i=maxn-3 ; i>=0 ; i--)IN[i] = amodb(IN[i+1]*(i+1));
      //for (int i=0 ; i<maxn ; i++)IN[i] = bigmod(F[i],mod-2);
}

ll combination(ll n, ll r)
{
      if (r>n)return 0;
      ll ret = amodb(IN[r]*IN[n-r]);
      ret = amodb(ret*F[n]);
      return ret;
}

int main()
{
      init();
      int tc;
      scanf("%d",&tc);

      for (int _t = 1; _t<=tc ; _t++){
            ll n,k;
            scanf("%lld %lld",&k,&n);
            for (int i=0 ; i<k ; i++){
                  ll a,b;
                  scanf("%lld %lld",&a,&A[i]);
                  A[i]-=a;
                  n-=a;
            }
            ll lim = 1;
            for (int i=0 ; i<k ; i++)lim*=2;

            ll ans = combination(n+k-1 , k-1);

            //show(ans);

            for (ll i=1 ; i<lim ; i++){
                  ll temp  = n , cnt = 0 , a = i;
                  for (ll j = 0 ; j<k; j++){
                        if (a&1){
                             cnt++;
                             temp-=(A[j]+1);
                        }
                        a/=2;
                  }
                  temp = combination(temp+k-1,k-1);
                  if (cnt&1)ans = amodb(ans+mod-temp);
                  else ans = amodb(ans+temp);
            }
            printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}
