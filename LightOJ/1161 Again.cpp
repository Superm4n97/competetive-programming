#include<bits/stdc++.h>
#define ll long long int
#define maxn 10004
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll d[maxn] , f[maxn] , g[maxn];

ll nc4(ll n)
{
      if (n<4)return 0;
      return n * (n-1) * (n-2) * (n-3) / 24;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            int n;
            scanf("%d",&n);

            memset(d,0,sizeof d);
            memset(f,0,sizeof f);
            memset(g,0,sizeof g);

            for (int i=1 ; i<=n; i++){
                  int a;
                  scanf("%d",&a);
                  d[a]++;
            }

            for (int i=maxn-4 ; i>0 ; i--){
                  for (int j = i ; j<maxn ; j+=i)f[i] += d[j];
                  g[i] = nc4(f[i]);
                  for (int j = i+i ; j<maxn ; j+=i)g[i] -= g[j];
            }
            printf("Case %d: %lld\n",_t,g[1]);
      }
      return 0;
}
/**
2 3 4 6 6

**/
