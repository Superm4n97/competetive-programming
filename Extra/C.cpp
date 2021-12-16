#include<bits/stdc++.h>
#define maxn 6003
#define ll long long
#define pb push_back
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector<ll> G[maxn];
ll levelMax[maxn] , L[maxn] ,A[maxn], vis[maxn],n,m,t;

void bfs()
{
      for (int i=0 ; i<maxn ; i++)L[i] = maxn*maxn+maxn;
      queue<ll>q;
      q.push(1);
      L[1] = 0;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            levelMax[L[u]] = max(levelMax[L[u]],A[u]);

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];
                  if (L[v]>L[u]+1){
                        L[v] = L[u]+1;
                        q.push(v);
                  }
            }
      }
}

int main()
{
      scanf("%lld %lld %lld",&n,&m,&t);
      for (int i=2 ; i<=n ; i++)scanf("%lld",&A[i]);

      for (int i=0 ; i<m ; i++){
            ll a, b;
            scanf("%lld %lld",&a,&b);
            if (a==b)continue;
            G[a].push_back(b);
            G[b].push_back(a);
      }

      bfs();

      for (int i=2 ; i<=t/2 ; i++){
            //levelMax[i] = max(levelMax[i],levelMax[i-1]+levelMax[1]);
            for (int j=1 ,k=i-1; j<=k ; j++,k--){
                  levelMax[i] = max(levelMax[i],levelMax[j]+levelMax[k]);
            }
      }

      for (int i=1 ; i<=t ; i++){
            printf("%lld ",levelMax[i/2]);
      }
      printf("\n");


      return 0;
}
/*
4 3 10
3 7 11
1 2
2 3
3 4
*/
