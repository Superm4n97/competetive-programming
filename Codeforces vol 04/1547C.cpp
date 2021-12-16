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
            ll n,m,k;
            scl(k) , scl(n) , scl(m);
            ll A[n+5] , B[m+5];

            for (int i=1 ; i<=n ; i++)scl(A[i]);
            for (int i=1 ; i<=m ; i++)scl(B[i]);

            vector<ll> ans;

            ll x = 1 , y = 1 , sol = 1;
            while(x<=n || y<=m){
                  if (x>n){
                        if (B[y]>k){
                              sol = 0;
                              break;
                        }
                        else {
                              if (B[y]==0)k++;
                              ans.push_back(B[y]);
                              y++;
                        }
                  }
                  else if (y>m){
                        if (A[x]>k){
                              sol = 0;
                              break;
                        }
                        else {
                              if (A[x]==0)k++;
                              ans.push_back(A[x]);
                              x++;
                        }
                  }
                  else{
                        if (A[x]>k && B[y]>k){
                              sol = 0;
                              break;
                        }
                        if (A[x]<=k){
                              if (A[x]==0)k++;
                              ans.push_back(A[x]);
                              x++;
                        }
                        else {
                              if (B[y]==0)k++;
                              ans.push_back(B[y]);
                              y++;
                        }
                  }
            }
            if (!sol)printf("-1\n");
            else {
                  for (int i=0 ; i<ans.size() ; i++)printf("%lld ",ans[i]);
                  printf("\n");
            }
      }


      return 0;
}
