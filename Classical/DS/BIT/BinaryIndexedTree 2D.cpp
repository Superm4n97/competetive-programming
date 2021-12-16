#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1003

using namespace std;

ll A[maxn][maxn] , BIT[maxn][maxn];
ll n,m;

void addElement(ll x, ll y, ll value)
{
      for( ll i = x; i<=n ; i+=i&-i){
            for (ll j=y ; j<=m ; j+=j&-j)BIT[i][j] += value;
      }
}

ll Prefix2dSum(ll x, ll y)
{
      ll ret = 0;
      for (ll i=x ; i>0 ; i-=i&-i){
            for (ll j=y ; j>0 ; j-=j&-j)ret+=BIT[i][j];
      }
      return ret;
}

ll reactangleSum(ll x1, ll y1, ll x2, ll y2)
{
      return Prefix2dSum(x2,y2)-Prefix2dSum(x1-1,y2)-Prefix2dSum(x2,y1-1)+Prefix2dSumd(x1-1,y1-1);
}

int main()
{
      scanf("%lld %lld",&n,&m);

      for (int i=1 ; i<=n; i++){
            for (int j = 1 ; j<=m; j++){
                  scanf("%lld",&A[i][j]);
                  addElement(i,j,A[i][j]);
            }
      }

      while(true){

            ll x1, x2, y2, y1;
            cin >> x1 >> y1 >> x2 >> y2;

            cout << reactangleSum(x1,y1,x2,y2) << endl;
      }


      return 0;
}
