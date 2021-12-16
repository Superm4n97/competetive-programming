#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define mod 1000000007

using namespace std;

ll F[maxn], IN[maxn], pre[maxn],csum[maxn];

ll amodb(ll a, ll b)
{
      return a - a/b*b;
}

ll bigmod(ll a, ll pw, ll md)
{
      if (pw == 0)return 1;

      ll temp = bigmod(a,pw/2,md);
      temp = amodb(temp*temp,md);
      if (temp%2)temp = amodb(temp*a,md);
      return temp;
}

void initialization()
{
      F[0] = 1;
      for (int i=1 ; i<maxn; i++)F[i] = amodb(F[i-1]*i,mod);
      IN[maxn-3] = bigmod(F[maxn-3],mod-2,mod);
      for (int i=maxn-4 ; i>=0 ; i--)IN[i] = amodb(IN[i+1]*i,mod);
}

ll nCr(ll n, ll r)
{
      if (r>n)return 0;
      ll ret = amodb(F[n]*IN[r],mod);
      return amodb(ret*IN[n-r],mod);
}

int main()
{
      initialization();
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n,m;
            scanf("%lld %lld",&n,&m);
            ll ans = 0 , total = bigmod(n,m,mod);

            pre[1] = csum[1] = 1;
            for (ll i = 2 ; i<=min(n,m) ; i++){
                  pre[i] =
            }

            for (ll i = 1 ; i<=min(n,m) ; i++){
                  ll temp = i;
                  temp = amodb(temp*nCr(n,i),mod);
                  temp = amodb(temp*nCr(m,i),mod);
                  temp = amodb(temp*F[i],mod);
                  //temp = amodb(temp*bigmod(i,m-i,mod),mod);
                  temp = amodb(temp*total,mod);
                  ans = amodb(ans+temp,mod);
            }
            printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}
