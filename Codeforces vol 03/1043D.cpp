#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

map < pair < ll, ll >, ll > mp;
ll n , m , A[13][maxn];

int main()
{
      cin >> n >> m;
      for (int i=1 ; i<=m ; i++){
            for (int j = 1 ; j<=n ; j++){

                  //cin >> A[i][j];
                  scanf("%I64d",&A[i][j]);

                  if (j>1)mp[{A[i][j-1],A[i][j]}]++;
            }
      }

      vector < ll > v;
      for (int i=2 ; i<=n ; i++){
            if (mp[{A[1][i-1],A[1][i]}]==m)v.push_back(1);
            else v.push_back(0);
      }

      for (int i=1 ; i<v.size() ; i++){
            if (v[i-1] && v[i]){
                  v[i]+=v[i-1];
                  v[i-1] = 0;
            }
      }

      ll ans = n;

      for (int i=0 ; i<v.size() ; i++){
            if (v[i]){
                  ll temp = v[i]*(v[i]+1)/2;
                  ans+=temp;
            }
      }

      cout << ans << "\n";


      return 0;
}
