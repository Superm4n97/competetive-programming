#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll phi[maxn] , ans[maxn];

void eulerTotient()
{
      for (int i=1; i<maxn ; i++)phi[i] = i;
      for (int i=2 ; i<maxn; i++){
            if (phi[i]==i){
                  for (int j=i ; j<maxn ; j+=i){
                        phi[j]/=i;
                        phi[j]*=(i-1);
                  }
            }
      }
      for (ll i=1 ; i<maxn ; i++){
            for (ll j = i ; j<maxn ; j+=i){
                  ans[j]+=phi[i]*i;
            }
      }
}

int main()
{
      eulerTotient();

      for (int i=1 ; i<=20 ; i++)cout << phi[i] << " ";
      cout << endl;

      int tc;
      //cin >> tc;
      scanf("%d",&tc);

      while(tc--){
            ll a;
            scanf("%lld",&a);
            //cin >> a ;
            printf("%lld\n",((ans[a]+1)*a)/2);
            //cout << ((ans[a]+1)*a)/2 << "\n";
      }

      return 0;
}
