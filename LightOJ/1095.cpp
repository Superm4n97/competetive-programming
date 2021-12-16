#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

ll D[1005] , C[1005][1005];

ll amodb(ll a, ll b)
{
      return a - a/b*b;
}

ll dearrangement(ll n)
{
      if (D[n]!=-1)return D[n];
      if (n==1)return 0;
      if (n==2 || n==0)return D[n] = 1;
      ll ret = amodb(dearrangement(n-1)+dearrangement(n-2),mod);
      return D[n] = amodb(ret*(n-1),mod);
}

ll nCr(ll n, ll r)
{
      if (r>n)return 0;
      if (C[n][r] != -1)return C[n][r];
      if (n==r || r==0)return C[n][r] = 1;
      if (r==1)return C[n][r] = n;

      return C[n][r] = amodb(nCr(n-1,r)+nCr(n-1,r-1) , mod);
}

using namespace std;

int main()
{
      memset(D,-1,sizeof D);
      memset(C,-1,sizeof C);
      int tc;
      scanf("%d",&tc);

      for(int _t = 1; _t<=tc ; _t++){
            ll n,m,k , ans = 0;
            scanf("%lld %lld %lld",&n,&m,&k);
            for (int i=0 ; i<=n-m ; i++){
                  ans = amodb(ans+amodb(dearrangement(n-k-i) * nCr(n-m,i), mod),mod);
            }
            printf("Case %d: %lld\n",_t,amodb(ans*nCr(m,k),mod));
      }

      return 0;
}
