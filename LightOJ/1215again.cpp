#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll solve(ll a, ll b, ll L)
{
      ll g = __gcd(a,b);
      ll lcm = a*b / g;
      L/=g;
      a/=g;
      b/=g;
      if (L%a!=0)return -1;
      L/=a;
      if (L%b!=0)return -1;
      L/=b;
      return L;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll a,b,L;
            scanf("%lld %lld %lld",&a,&b,&L);
            ll ans = solve(a,b,L);
            if (ans==-1)printf("Case %d: impossible\n",_t);
            else printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}
