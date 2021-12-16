#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;scl(tc);

      while(tc--){
            ll n,m;
            scl(n) , scl(m);

            ll A[n+5] , B[n+5] , C[m+5] , ans[m+5] , mp[n+5];
            memset(ans,0,sizeof ans);
            memset(mp,0,sizeof mp);

            priority_queue<pair<ll,ll> > need , have;

            for (int i=1 ; i<=n ; i++)scl(A[i]);
            for (int i=1 ; i<=n ; i++){
                  scl(B[i]);
                  mp[B[i]] = i;
                  if (A[i] != B[i])need.push({B[i] , i});
            }
            for (int i=1 ; i<=m ; i++){
                  scl(C[i]);
                  have.push({C[i],i});
            }

            while(!need.empty() && !have.empty()){
                  if (need.top().first != have.top().first){
                        have.pop();
                        continue;
                  }
                  ans[have.top().second] = need.top().second;

                  have.pop();
                  need.pop();
            }

            bool sol = true;

            if (!need.empty())sol = false;

            for (int i=m ; i>=1 ; i--){
                  if (ans[i]==0){
                        if (i==m){
                              if (mp[C[i]]==0)sol = false;
                              else ans[i] = mp[C[i]];
                        }
                        else ans[i] = ans[i+1];
                  }
            }
            if (sol==false)printf("NO\n");
            else {
                  printf("YES\n");
                  for (int i=1 ; i<=m ; i++)printf("%I64d ",ans[i]);
                  printf("\n");
            }
      }

      return 0;
}
