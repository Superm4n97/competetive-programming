#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

vector < ll > G[maxn];
ll n,C[maxn] , ans = 0 , degree[maxn] , vis[maxn];
map < pair < ll, ll > , ll > mp;

int main()
{
      cin >> n;

      for (int i=1 ; i<=n ; i++){
            cin >> C[i];
            ans = max(ans,C[i]);
      }

      for (int i=1 ; i<n ; i++){

            ll a,b,c;
            cin >> a >> b >> c;

            G[a].push_back(b);
            G[b].push_back(a);

            degree[a]++;
            degree[b]++;

            mp[{a,b}] = c;
            mp[{b,a}] = c;
      }

      queue < ll > q;

      for (int i = 1 ; i<=n ; i++){
            if(degree[i]==1){
                  q.push(i);
            }
      }

      while(!q.empty()){
            ll u = q.front() , Parent = 0;
            q.pop();

            vector < ll > childs;

            for (int i=0 ; i<G[u].size() ; i++){

                  ll v = G[u][i];
                  if (vis[v]){
                        childs.push_back(C[v]);
                  }
                  else Parent = v;
            }
            if (childs.empty()){
                  C[u] = C[u] - mp[{u,Parent}];
                  if (C[u]<0)C[u] = 0;

                  degree[Parent]--;
                  if (degree[Parent]==1)q.push(Parent);

                  vis[u] = 1;
            }
            else {
                  sort(childs.rbegin(),childs.rend());


                  /*if (u==2){
                        show(C[u]);
                  }*/

                  if (childs.size()>1){

                        /*show(u);
                        show(childs[0]);
                        show(childs[1]);*/

                        ll temp = childs[0] + childs[1] + C[u];
                        ans = max(ans,temp);
                  }

                  C[u] += childs[0];
                  ans = max(ans,C[u]);

                  if (Parent!=0){
                        C[u] -= mp[{u,Parent}];
                        if (C[u]<0)C[u] = 0;

                        degree[Parent]--;
                        if(degree[Parent]==1)q.push(Parent);
                  }

                  vis[u] = 1;
            }
      }

      //for (int i=1 ; i<=n ; i++)cout << i << " "  << C[i] << endl;

      cout << ans << endl;



      return 0;
}
