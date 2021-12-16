#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll n,I , A[maxn], csum[maxn] , need = 1;
vector < ll > v;
map < ll,ll > mp;

int main()
{
      scanf("%I64d %I64d",&n, &I);
      need = (I*8)/n;

      if (need>20){
            cout << 0 << endl;
            return 0;
      }

      need = 1<<need;

      for (ll i=1 ; i<=n ;i++){
            ll a;
            scanf("%I64d",&a);

            mp[a]++;
            if (mp[a]==1)v.push_back(a);
      }

      if (v.size()<=need){
            cout << 0 << endl;
            return 0;
      }

      sort(v.begin(),v.end());

      for (int i=0 ; i<v.size() ; i++){
            csum[i+1] = mp[v[i]];
            csum[i+1]+=csum[i];
      }

      ll ans = 0;

      for (int i=1 ; i+need <= v.size() ; i++){
            ans = max(ans,csum[i+need] - csum[i]);
      }



      cout << n - ans << endl;



      return 0;
}
