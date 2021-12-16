#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

double ans[maxn], d[maxn];

int main()
{
      for (int i=1 ; i<maxn ; i++){
            if (i>1){
                  ans[i] = (ans[i]+1)/d[i];
            }
            for (int j=i+i ; j<maxn ; j+=i){
                  ans[j]+=(ans[i]+1);
                  d[j]+=1;
            }
      }

      int tc;
      scanf("%d",&tc);

      for (int i=1 ; i<=tc ; i++){
            ll n;
            scanf("%lld",&n);
            printf("Case %d: %.7lf\n",i,ans[n]);
      }

      return 0;
}
