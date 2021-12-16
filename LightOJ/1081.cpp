#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 505

using namespace std;

ll n,q,mx[maxn][maxn][20];

void buildSparse()
{
      for (ll b = 1 ; b<15 ; b++){
            for (ll i = 1 ; i<=n && (i-1+(1LL<<b)) <= n ; i++){
                  for (int j=1 ; j<=n && (j-1+(1LL<<b)) <= n ; j++){
                        ll x = i+(1LL<<(b-1)) , y = j+(1LL<<(b-1));
                        mx[i][j][b] = max(max(mx[i][y][b-1],mx[x][j][b-1]),max(mx[i][j][b-1],mx[x][y][b-1]));
                  }
            }
      }
}

ll quary(ll x, ll y, ll s, ll b)
{
      if (s==0 || b==-1)return 0;
      if ((s&(1LL<<b)) == 0)return quary(x,y,s,b-1);

      ll sz = (1LL<<b);
      ll x_new = x+sz , y_new = y+sz;
      ll ret1 = mx[x][y][b], ret2 = mx[x+s-sz][y][b], ret3 = mx[x][y+s-sz][b], ret4 = quary(x_new,y_new,s-(1LL<<b),b-1);

      return max(max(ret1,ret2),max(ret3,ret4));
}

int main()
{
      int tc;
      scanf("%lld",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%lld %lld",&n,&q);
            memset(mx,-1,sizeof mx);

            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=n ; j++){
                        scanf("%lld",&mx[i][j][0]);
                  }
            }

            buildSparse();
            printf("Case %d:\n",_t);

            while(q--){
                  ll I, J, S;
                  scanf("%lld %lld %lld",&I,&J,&S);
                  printf("%lld\n",quary(I,J,S,14));
            }
      }
}
