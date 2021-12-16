#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10000007

using namespace std;

int M[maxn];

ll mobious()
{
      M[1] = 1;
      for (int i = 1 ; i<maxn ; i++){
            if (M[i]==0)continue;
            for (int j = i+i ; j<maxn ; j+=i)M[j]+=(-M[i]);
      }
}

int main()
{
      mobious();

      int tc;
      scanf("%d",&tc);
      while(tc--){
            ll n;
            scanf("%lld",&n);
            ll lim = sqrt(n)+1 , ans = 0;

            for (ll i = 1 ; i<=lim ; i++){
                  ans += (n/(i*i))*M[i];
            }
            printf("%lld\n",ans);
      }

      return 0;
}
