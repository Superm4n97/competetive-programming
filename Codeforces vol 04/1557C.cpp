#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;

      ll temp = bigmod(a,p/2);
      temp = amod(temp*temp);
      if (p&1LL)temp = amod(temp*a);

      return temp;
}

int main()
{
//      show(bigmod(2,mod-2));
//      show(amod(500000004+500000004));
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n,k;
            scanf("%lld %lld",&n,&k);

            ll ans = bigmod(2,n-1);
            if (n%2==1)ans = amod(ans+1);
            ans = bigmod(ans,k);

            printf("%lld\n",ans);
      }

      return 0;
}
/*
000
000
000

2 2
3 2
000,011,101,110,111


(2^n-1 + (n&1)))^k

1 - 1
2 - 2
3 - 4
4 - 1+6+4+1
4C0 + 4C1 + 4C2 + 4C3 + 4C4
1      4     6     4     1

1 5 10 10 5 1
1 6 15 20 15 6 1

4*3*2/2*3
*/
