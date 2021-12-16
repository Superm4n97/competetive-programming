#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x)         cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            200005

using namespace std;

vector < ll > G[maxn];
ll C[maxn] , X[maxn] , H[maxn] , good[maxn] , n,  m;
bool sol = true;

void clean()
{
      sol = true;
      for (int i=0 ; i<=n+3 ; i++){
            G[i].clear();
            C[i] = 0;
      }
}

void countChild(ll u, ll p)
{
      //show(u);
      C[u] = X[u];

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (v!=p){

                  countChild(v,u);
                  C[u]+=C[v];
            }
      }
}

void dfs(ll u, ll p)
{
      ll gain = 0;

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v!=p){
                  dfs(v,u);
                  gain+=good[v];
            }
      }

      ll temp = H[u];
      if (temp<0)temp*=-1;

      if (temp>C[u]){
            sol = false;
            //show('1');
      }

      ll tut = C[u] - temp;

      if (tut%2){
            sol = false;
            /*show('2');
            show(u);
            show(C[u]);
            show(H[u]);
            show(temp);
            show(tut);
            */
      }

      tut/=2;

      ll have = tut;
      if (H[u]>0)have+=H[u];

      if (gain>have){
            sol = false;
            //show('3');
      }

      good[u] = have;
}

int main()
{
      int tc;
      cin >> tc ;
      while(tc--){

            clean();

            cin >> n >> m;

            for (int i=1 ; i<=n ; i++)cin >> X[i];
            for (int i=1 ; i<=n ; i++)cin >> H[i];

            for (int i=1 ; i<n ; i++){
                  ll a, b;
                  cin >> a >> b;
                  G[a].pb(b);
                  G[b].pb(a);
            }

            //show('1');

            countChild(1 , 0);

            //show('10');

            dfs(1,0);

            cout << (sol?"YES":"NO") << endl;

      }


      return 0;
}
