#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll P[maxn];

ll initialize()
{
      for (int i=1 ; i<maxn ; i++)P[i] = 1;
      for (int i=2 ; i<maxn ; i++){
            if (P[i]==1){
                  for (int j=i+i ; j<maxn ; j+=i)P[j] = 0;
            }
      }
      for (int i=2 ; i<maxn ;i++)P[i] += P[i-1];
}
int main()
{
      initialize();

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n,k;
            scanf("%lld %lld",&n,&k);

            ll lim = 1 , A[k+2];
            for (int i=0 ; i<k ; i++){
                  scanf("%lld",&A[i]);
                  lim*=2;
            }

            if (k)sort(A,A+k);

            ll ans = 0 , offset = 0;

            if (A[0]<=n)offset++;

            for (int i=1 ; i<k ; i++){
                  if (A[i]!=A[i-1] && A[i]<=n)offset++;
            }

            for (int i=1 ; i<lim ; i++){
                  ll temp = i , cnt = 0 , lcm  = 1;
                  for (int j=0 ; j<k ; j++){
                        if (temp&1){
                              cnt++;
                              ll g = __gcd(lcm,A[j]);
                              lcm = A[j]*lcm/g;
                        }
                        temp/=2;
                  }
                  if (cnt&1)ans+=(n/lcm);
                  else ans-=(n/lcm);
            }
            printf("Case %d: %lld\n",_t,n-ans-P[n]+offset);
      }
}
