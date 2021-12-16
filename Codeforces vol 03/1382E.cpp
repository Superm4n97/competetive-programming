#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define scl(x) scanf("%d",&x)

using namespace std;

int n,m , P[maxn] , A[maxn] , ans = 0;
vector < int > G[maxn];

int findParent(ll a)
{
      if(P[a]==a)return a;
      return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);

      if (a!=b)P[b]=a;
}

int main()
{
      for (int i=0 ; i<maxn ; i++)P[i] = i;


      scl(n);
      scl(m);

      for (int i=1 ; i<=n ; i++){
            scl(A[i]);
      }


      for (int i=1 ; i<n ; i++){
            ll a = A[i] , b = A[i+1];

            if (a!=b){

                  G[a].push_back(b);
                  G[b].push_back(a);

                  ans++;
            }
      }


      printf("%d\n",ans);

      for (int i=1 ; i<m ; i++){
            ll x, y;
            scl(y);
            scl(x);

            x = findParent(x) , y = findParent(y);


            for (int j = 0 ; j<G[x].size() ; j++){
                  ll v = G[x][j];

                  v = findParent(v);

                  if (v==x || v==y){
                        if (v==y)ans--;
                  }

                  G[y].push_back(v);

            }
            printf("%d\n",ans);

            makeParent(y,x);
      }



      return 0;
}
