#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005
#define inf 100000000000014

using namespace std;

ll n,r,MX[maxn] , X[maxn] , Y[maxn] , ans[maxn] , T[maxn];

int main()
{
      scanf("%I64d %I64d",&r,&n);
      for (int i=1 ; i<=n ; i++)scanf("%I64d %I64d %I64d",&T[i],&X[i],&Y[i]);

      for (int i=1 ; i<=n ; i++){

            if (X[i]+Y[i]-2>T[i])ans[i] = -inf;
            else ans[i] = 1;

            for (int j=1 ; j<=2*r+4 ; j++){

                  ll id = i-j;
                  if (id<0)break;

                  if (abs(X[id]-X[i])+abs(Y[id]-Y[i]) <= T[i]-T[id]){

                        ans[i] = max(ans[id]+1 , ans[i]);
                  }
            }
            if (i>=2*r)ans[i] = max(ans[i],MX[i-2*r]+1);
            MX[i] = max(MX[i-1],ans[i]);
      }

      printf("%I64d\n",MX[n]);


      return 0;
}
