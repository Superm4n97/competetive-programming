#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n,C[maxn] , A[maxn];
vector < ll > G[maxn];

void dfs(ll u , ll p)
{
      if (C[u]==0)A[u] = -1;
      else A[u] = 1;

      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];
            if (v!=p){

                  dfs(v,u);
                  if (A[v]>0)A[u]+=A[v];
            }
      }

      return;
}

void reRooting(ll u, ll p)
{
      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];
            if (v!=p){

                  if (A[v]<0){

                        A[v] = max(A[u]-1,-1LL);
                  }
                  else {

                        ll temp = A[u] - A[v];
                        if (temp>0)A[v]+=temp;
                  }

                  reRooting(v,u);
            }
      }
}

int main()
{
      cin >> n;
      for (int i=1 ; i<=n ; i++)cin >> C[i];

      for (int i = 1 ; i<n;i++){

            ll a, b;
            cin >> a>> b;

            G[a].push_back(b);
            G[b].push_back(a);
      }

      dfs(1,0);

      /*
      for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
      cout << endl;*/

      reRooting(1,0);

      for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
      cout << endl;

      return 0;
}
