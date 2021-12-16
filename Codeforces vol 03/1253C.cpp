#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "  << x << endl
#define maxn 200005

using namespace std;

ll csum[maxn] , ans[maxn] , n , m;
vector < ll > v;

int main()
{
      cin >> n >> m;

      for (int i=0; i<n;i++){
            ll a;
            cin >> a;
            v.push_back(a);
      }

      sort(v.begin(),v.end());

      for (int i=1 ; i<=n ; i++){
            csum[i] = v[i-1];
            csum[i]+=csum[i-1];
      }

      for (int i=1 ; i<=n ; i++){
            if (i<=m)ans[i] = csum[i];
            else {
                  ans[i] = csum[i]+ans[i-m];
            }
      }

      for (int i=1 ; i<=n ; i++)cout << ans[i] << " ";
      cout << endl;

      return 0;
}
