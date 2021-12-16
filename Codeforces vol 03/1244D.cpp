#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

vector < ll > G[maxn];
ll C[maxn][5] , n , L[maxn] , a , b , c;
bool sol = true;

void dfs(ll u, ll p)
{
      if (G[u].size()>2)sol = false;

      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];
            if (v!=p){
                  L[v] = L[u]+1;
                  dfs(v,u);
            }
      }
}

int main()
{
      //for (int i=0 ; i<maxn; i++)L[i] = maxn;

      cin >> n;

      for (int i=1; i<=n ; i++)cin >> C[i][1];
      for (int i=1; i<=n ; i++)cin >> C[i][2];
      for (int i=1; i<=n ; i++)cin >> C[i][3];

      for (int i=1 ; i<n ; i++){
            ll a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
      }

      for (int i=1 ; i<=n ; i++){
            if (G[i].size()==1){
                  L[i] = 0;
                  dfs(i,0);
                  break;
            }
      }

      if (!sol){
            cout << -1 << endl;
            return 0;
      }

      ll t1 = 0, ans = 100000000000000017;

      for (int i=1 ; i<=n ; i++){
            ll temp = L[i]%3;
            if (temp==0)t1+=C[i][1];
            if (temp==1)t1+=C[i][2];
            if (temp==2)t1+=C[i][3];
      }
      if (ans>t1){
            ans = t1;
            a = 1;
            b = 2;
            c = 3;
      }
      t1 = 0;

      for (int i=1 ; i<=n ; i++){
            ll temp = L[i]%3;
            if (temp==0)t1+=C[i][1];
            if (temp==1)t1+=C[i][3];
            if (temp==2)t1+=C[i][2];
      }
      if (ans>t1){
            ans = t1;
            a = 1;
            b = 3;
            c = 2;
      }
      t1 = 0;

      for (int i=1 ; i<=n ; i++){
            ll temp = L[i]%3;
            if (temp==0)t1+=C[i][2];
            if (temp==1)t1+=C[i][1];
            if (temp==2)t1+=C[i][3];
      }
      if (ans>t1){
            ans = t1;
            a = 2;
            b = 1;
            c = 3;
      }
      t1 = 0;

      for (int i=1 ; i<=n ; i++){
            ll temp = L[i]%3;
            if (temp==0)t1+=C[i][2];
            if (temp==1)t1+=C[i][3];
            if (temp==2)t1+=C[i][1];
      }
      if (ans>t1){
            ans = t1;
            a = 2;
            b = 3;
            c = 1;
      }
      t1 = 0;

      for (int i=1 ; i<=n ; i++){
            ll temp = L[i]%3;
            if (temp==0)t1+=C[i][3];
            if (temp==1)t1+=C[i][1];
            if (temp==2)t1+=C[i][2];
      }
      if (ans>t1){
            ans = t1;
            a = 3;
            b = 1;
            c = 2;
      }
      t1 = 0;

      for (int i=1 ; i<=n ; i++){
            ll temp = L[i]%3;
            if (temp==0)t1+=C[i][3];
            if (temp==1)t1+=C[i][2];
            if (temp==2)t1+=C[i][1];
      }
      if (ans>t1){
            ans = t1;
            a = 3;
            b = 2;
            c = 1;
      }
      t1 = 0;

      cout << ans << endl;
      for (int i=1 ; i<=n ; i++){
            ll temp = L[i]%3;
            if (temp==0)cout << a << " ";
            else if (temp==1)cout << b << " ";
            else cout << c << " ";
      }



      return 0;
}
