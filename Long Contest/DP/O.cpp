#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 16
#define maxMask 65536

using namespace std;

struct point
{
      ll x, y;
} A[maxn];
ll dp[maxn][maxMask],n;

bool linear(ll a, ll b, ll c)
{
      if ((A[a].y-A[b].y)*(A[b].x-A[c].x)==(A[a].x-A[b].x)*(A[b].y-A[c].y))return true;
      return false;
}

ll new_mask(ll a, ll b, ll mask)
{
      mask = (mask | (1LL<<a) | (1LL<<b));
      for (ll i=a+1 ; i<n ; i++){
            if (i==a || i==b || (mask&(1LL<<i)))continue;
            if (linear(a,b,i))mask = (mask|(1LL<<i));
      }
      return mask;
}

ll rec(ll pos, ll mask)
{
//      show(mask);
      if (pos==n)return 0;
      if (dp[pos][mask] != -1)return dp[pos][mask];

      ll p = (1LL<<pos);
      if (mask&p)return dp[pos][mask] = rec(pos+1,mask);

      ll ret = rec(pos+1,mask|p)+1;

      for (ll i=pos+1 ; i<n ; i++){
            ll q = (1LL<<i);
            if ((q&mask)==0){
                  ret = min(ret,rec(pos+1,new_mask(pos,i,mask))+1);
            }
      }
      return dp[pos][mask] = ret;
}

int main()
{
      int tc;
      scanf("%lld",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%lld",&n);
            for (int i=0 ; i<n ; i++){
                  ll a,b;
                  scanf("%lld %lld",&a,&b);
                  A[i].x = a;
                  A[i].y = b;
            }
            memset(dp,-1,sizeof dp);
            printf("Case %d: %lld\n",_t,rec(0,0));
      }

      return 0;
}
