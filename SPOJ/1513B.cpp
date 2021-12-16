#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007
#define maxn 200005

using namespace std;

ll A[maxn] , F[maxn];

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll C(ll n,ll r)
{
      if (r>n)return 0;
      return amod(n*(n-1));
}

int main()
{
      F[0] = 1;
      for (ll i = 1 ; i<maxn ; i++)F[i] = amod(F[i-1]*i);

      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);
            for (int i=0 ; i<n ; i++)scanf("%lld",&A[i]);

            ll _and = A[0] , cnt = 0;

            for (int i=1 ; i<n ; i++)_and = (A[i]&_and);
            for (int i=0 ; i<n ; i++){
                  if (_and==A[i])cnt++;
            }
            printf("%lld\n",amod(F[n-2]*C(cnt,2)));
      }

      return 0;
}
/*
001
011
101
001
*/
