#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

ll n,u,v;

ll check(ll x, ll y)
{
      ll ret = 0;
      if (x==y) ret = min(v+v,v+u);
      else if (abs(x-y)==1)ret = min(v,u);
      return ret;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n),scl(u),scl(v);

            ll A[n+6] , ans = 100000000000014;
            for (int i=1 ; i<=n ; i++)scl(A[i]);

            for (int i=1 ; i<=n ; i++){
                  if (i==1){
                        ans = min(ans,check(A[i],A[i+1]));
                  }
                  else if (i==n){
                        ans = min(ans,check(A[i],A[i-1]));
                  }
                  else {
                        ans = min(ans,check(A[i],A[i-1]));
                        ans = min(ans,check(A[i],A[i+1]));
                  }
            }

            printf("%I64d\n",ans);
      }

      return 0;
}
