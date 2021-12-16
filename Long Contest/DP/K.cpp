#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007
#define maxn 1005

ll d[maxn][maxn], ncr[maxn][maxn], F[maxn];

ll C(ll n, ll r)
{
      if (ncr[n][r] != -1) return ncr[n][r];
      if (r==0 || n==r)return ncr[n][r] = 1;
      if (r>n)return ncr[n][r] = 0;

      return ncr[n][r] = (C(n-1,r)+C(n-1,r-1))%mod;
}

ll dng(ll n, ll rest)
{
      if (d[n][rest] != -1)return d[n][rest];
      if (n==0)return d[n][rest] = 1;
      if (n==1)return d[n][rest] = rest;

      return d[n][rest] = ((rest*dng(n-1,rest))%mod + ((n-1)*(dng(n-1,rest)+dng(n-2,rest))%mod)) % mod;
}

void init()
{
      memset(ncr,-1,sizeof ncr);
      memset(d,-1,sizeof d);
      F[0] = 1;
      for (ll i=1 ; i<maxn ; i++)F[i] = (F[i-1]*i)%mod;

}

int main()
{
      init();
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            ll n,m,k;
            scanf("%lld %lld %lld",&n,&m,&k);
            ll ans = ((C(m,k)*dng(m-k,n-m))%mod * F[n-m])%mod;
            printf("Case %d: %lld\n",_t,ans);
      }
}
/*
ncr*derangement*F
*/
