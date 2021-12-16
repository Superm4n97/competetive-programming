#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 3000006

using namespace std;

ll phi[maxn] , sum[maxn];

void eularTotient()
{
      for (int i=1 ; i<maxn ; i++)phi[i] = i;

      for (int i=2 ; i<maxn ; i++){
            if (phi[i]==i){
                  for (int j = i ; j<maxn ; j+=i){
                        phi[j] = phi[j]*(i-1)/i;
                  }
            }
      }
      for (int i=1 ; i<maxn ; i++){
            for (int j=i ; j<maxn ; j+=i){
                  sum[j] += phi[i]*i;
            }
      }

      for (int i=1;i<maxn ; i++){
            sum[i] = (sum[i]+1)*i/2;
            sum[i] += sum[i-1];
      }
}

int main()
{
      eularTotient();

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n;
            scanf("%lld",&n);
            printf("Case %d: %lld\n",_t,sum[n]);
      }

      return 0;
}
