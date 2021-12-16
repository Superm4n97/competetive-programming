#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n,m;
            scl(n) , scl(m);
            ll k[n+5] , C[m+5];
            vector<ll> v;
            for (int i=1 ; i<=n ; i++){
                  scl(k[i]);
                  v.push_back(k[i]);
            }
            for (int i=1 ; i<=m ; i++)scl(C[i]);

            sort(v.rbegin(),v.rend());

            ll t = 1 , ans = 0;

            for (int i=0 ; i<n ; i++){
                  if (v[i]>=t){
                        ans+=C[t];
                        t++;
                  }
                  else {
                        ans+=C[v[i]];
                  }
            }
            printf("%I64d\n",ans);

      }

      return 0;
}
