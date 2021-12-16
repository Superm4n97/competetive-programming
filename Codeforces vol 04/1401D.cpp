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

#define maxn            100005
#define mod 1000000007

using namespace std;

vector < ll > G[maxn] , X,Y;
ll n,m , child[maxn] , ans;


void clean()
{
      ans = 0;
      for (ll i=0 ; i<=n+2 ; i++){
            G[i].clear();
            child[i] = 0;
      }
      X.clear();
      Y.clear();
}

void dfs(ll u, ll p)
{
      child[u] = 1;

      for (ll i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];

            if (v!=p){

                  dfs(v,u);
                  ll a = child[v];
                  ll b = n-a;

                  ll temp = a*b;
                  //temp%=mod;

                  X.push_back(temp);

                  child[u]+=child[v];
            }
      }
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            scl(n);

            clean();

            for (ll i=1 ; i<n ; i++){

                  ll a,b;
                  scll(a,b);

                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            dfs(1,0);

            scl(m);

            for (ll i=0 ; i<m ; i++){

                  ll a;
                  scl(a);

                  Y.push_back(a);
            }

            rsrt(Y);

            if (m<n-1){
                  for (int i=0 ; i<n-1-m ; i++)Y.push_back(1);
            }
            else if (m>n-1){

                  vector < ll > Z;
                  ll temp = Y[0];
                  for (int i=1 ; i<=m-n+1 ; i++){
                        temp *= Y[i];
                        temp%=mod;
                  }
                  Z.push_back(temp);
                  for (int i=m-n+2 ; i<m ; i++)Z.push_back(Y[i]);

                  Y = Z;
            }

//            for (int i=0 ; i<Y.size() ; i++)cout << Y[i] << " ";
//            cout << endl;

            rsrt(X);


            for (ll i=0 ; i<X.size() ; i++){
                  X[i]%=mod;
                  Y[i]%=mod;

                  ll temp = (X[i]*Y[i])%mod;

                  ans+=temp;
                  ans%=mod;
            }

            printf("%I64d\n",ans);

      }



      return 0;
}

/**

3
1 2
1 3
4
2 2 2 2

*/
