#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n,m;
            scl(n),scl(m);

            ll A[n+5], cnt[n+5];
            memset(cnt,0,sizeof cnt);

            for (int i=1 ; i<=n ; i++){
                  scl(A[i]);
                  if (A[i]<=i)cnt[i-A[i]]++;
                  else {
                        cnt[n+i-A[i]]++;
                  }
            }

            ll mv = max(0LL,n-m*2);

            vector<ll>ans;
            for (int i=0 ; i<n ; i++){
                  if (cnt[i]>=mv)ans.push_back(i);
            }
            printf("%d ",ans.size());
            for (int i=0 ; i<ans.size() ; i++)printf("%lld ",ans[i]);
            printf("\n");
      }

      return 0;
}
/*
1
10 2
10  4 3 2 1  5 6 7 8 9
*/
