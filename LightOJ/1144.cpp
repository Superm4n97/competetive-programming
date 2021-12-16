#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define maxn 1000006

using namespace std;

ll M[maxn];

void mobious()
{
      M[1] = 1;
      for (int i=1 ; i<maxn ; i++){
            for (int j=i+i ; j<maxn ; j+=i)M[j] -= M[i];
      }
}

int main()
{
      mobious();
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){

            ll n, m;
            scanf("%lld %lld",&n,&m);

            if (n>m)swap(n,m);

            if (m==0){
                  printf("Case %d: 0\n",_t);
                  continue;
            }
            if (n==0){
                  printf("Case %d: 1\n",_t);
                  continue;
            }

            ll ans = 0;

            for (int i=1 ; i<=n ; i++){
                  ll a = m/i , b = n/i;
                  ans += (M[i]*(a * b));
            }

            printf("Case %d: %lld\n",_t,ans+2);
      }

      return 0;
}
