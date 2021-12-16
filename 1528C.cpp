#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 4000006

using namespace std;

ll n,ans,endingTime[maxn],startingTime[maxn],have[maxn] ,maxEnd[maxn],tme,currentNodes,nodeEndedAt[maxn];
vector<ll> S[maxn],K[maxn];

void clean()
{
      ans = currentNodes = tme = 0;
      for (int i=0 ; i<=n+3 ; i++){
            S[i].clear();
            K[i].clear();
      }
      for (int i=0 ; i<8*n+3 ; i++){
            endingTime[i] = maxEnd[i] = -1;
            have[i] = 0;
      }
}

void timeDFS(ll u)
{
      tme++;
      ll strt = tme;
      startingTime[u] = tme;
      for (int i=0 ; i<K[u].size() ; i++){
            ll v = K[u][i];
            timeDFS(v);
      }
      tme++;
      endingTime[strt] = tme;
      nodeEndedAt[tme] = u;
}


ll findMax(ll node, ll b, ll e, ll x, ll y)
{
      if (x>y || b>y || e<x)return -1;
      if (b>=x && e<=y)return maxEnd[node];

      ll L = node*2, R = node*2+1, mid = (b+e)/2;
      return max(findMax(L,b,mid,x,y),findMax(R,mid+1,e,x,y));
}

void update(ll node, ll b, ll e, ll idx, ll val)
{
      if (b==e && b==idx){
            maxEnd[node] = val;
            return;
      }
      if (b>idx || e<idx)return;

      ll L = node*2, R = node*2+1, mid = (b+e)/2;
      update(L,b,mid,idx,val);
      update(R,mid+1,e,idx,val);

      maxEnd[node] = max(maxEnd[L],maxEnd[R]);
}

void check(ll u)
{
      ll strt = startingTime[u];
      ll ed = endingTime[strt];
      if (findMax(1,1,tme,strt,ed)>strt)return;
      else {
            ll mx = findMax(1,1,tme,1,strt-1);
//            show(strt);
            if (mx>ed){
                  show(mx);
                  show(nodeEndedAt[mx]);
                  show(startingTime[4]);

                  update(1,1,tme,startingTime[nodeEndedAt[mx]],-1);
                  have[nodeEndedAt[mx]] = -1;
                  currentNodes--;
                  cout << "1 : deleted: ";
                  show(nodeEndedAt[mx]);
            }
            update(1,1,tme,startingTime[u],endingTime[startingTime[u]]);

            cout << "inserted : ";
            show(u);

            have[u] = 1;
            currentNodes++;

      }
}

void DFS(ll u)
{
      check(u);
      ans = currentNodes;

      for (int i=0 ; i<S[u].size() ; i++){
            ll v = S[u][i];
            DFS(v);
      }
      if (have[u]==1){
            update(1,1,tme,startingTime[u],-1);
            have[u] = 0;
            currentNodes--;

            cout << "2 : deleted: ";
            show(u);
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);
      while(tc--){
            scanf("%lld",&n);
            clean();

            for (int i=2 ; i<=n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  S[a].push_back(i);
            }
            for (int i=2 ; i<=n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  K[a].push_back(i);
            }
            timeDFS(1);
            tme++;
            //build(1,1,tme);

            DFS(1);
            printf("%lld\n",ans);
      }


      return 0;
}
/*
1 2 3 3 6 6 2 4 5 7 7 5 4 1
*/
