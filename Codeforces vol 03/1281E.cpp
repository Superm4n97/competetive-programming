#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005

using namespace std;

vector < ll > G[maxn] , W[maxn];
ll n , C[maxn] , ansMin , ansMax;

void clean()
{
      ansMax = ansMin = 0;

      for (int i=0 ; i<=n+2 ; i++){

            G[i].clear();
            W[i].clear();
            C[i] = 0;
      }
}

void calculateChild(ll u ,ll p)
{
      C[u] = 1;

      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];
            if (v!=p){
                  calculateChild(v,u);
                  C[u]+=C[v];
            }
      }
}

void solveMin(ll u , ll p)
{
      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];

            if (v!=p){

                  if (C[v]%2)ansMin+=W[u][i];
                  solveMin(v,u);
            }
      }
}

void solveMax(ll u, ll p)
{
      for (int i=0 ; i<G[u].size() ; i++){

            ll v = G[u][i];

            if (v!=p){
                  ansMax+=(min(C[v] , n - C[v])*W[u][i]);
                  solveMax(v,u);
            }
      }
}



int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            cin >> n;
            n*=2;

            clean();

            for (int i=1 ; i<n ; i++){
                  ll a, b , c;
                  cin >> a >> b >>  c;

                  G[a].push_back(b);
                  G[b].push_back(a);
                  W[a].push_back(c);
                  W[b].push_back(c);
            }

            calculateChild(1 , 0);
            solveMin(1 , 0);
            solveMax(1 , 0);

            cout << ansMin << " " << ansMax << endl;
      }

      return 0;
}
