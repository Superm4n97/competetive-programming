#include<bits/stdc++.h>
#define maxn 200005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int n,start[maxn],finished[maxn] , sp[maxn][23] ,N;
vector<int>G[maxn],E,L,msort[4*maxn];

void eular(int u,int level)
{
      E.push_back(u);
      start[u] = E.size()-1;
      L.push_back(level);

      for (int i=0 ; i<G[u].size() ; i++)eular(G[u][i],level+1);

      E.push_back(u);
      finished[u] = E.size()-1;
      L.push_back(0);
      return;
}

void build(int node, int b, int e)
{
      if (b==e){
            msort[node].push_back(L[b]);
            return;
      }

      int mid = (b+e)/2 , l=node*2, r=node*2+1;
      build(l,b,mid);
      build(r,mid+1,e);
      {
            int x = 0 , y = 0;
            while(x<msort[l].size() || y<msort[r].size()){
                  if (y>=msort[r].size()){
                        msort[node].push_back(msort[l][x]);
                        x++;
                  }
                  else if (x>=msort[l].size()){
                        msort[node].push_back(msort[r][y]);
                        y++;
                  }
                  else {
                        if (msort[l][x]<msort[r][y]){
                              msort[node].push_back(msort[l][x]);
                              x++;
                        }
                        else {
                              msort[node].push_back(msort[r][y]);
                              y++;
                        }
                  }
            }
      }
      return;
}

int searchMsortArray(int node, int val)
{
      int beg = 0 , ed = msort[node].size()-1 , ret_low = msort[node].size() , ret_high = -1;
      while(beg<=ed){
            int b_mid = (beg+ed)/2;
            if (msort[node][b_mid]<=val){
                  if (msort[node][b_mid] == val)ret_high = max(ret_high,b_mid);
                  beg = b_mid+1;
            }
            else {
                  ed = b_mid-1;
            }
      }

      if (ret_high==-1)return 0;

      beg = 0 , ed = msort[node].size()-1;

      while(beg<=ed){
            int b_mid = (beg+ed)/2;
            if (msort[node][b_mid]>=val){
                  if (msort[node][b_mid] == val)ret_low = min(ret_low,b_mid);
                  ed = b_mid-1;
            }
            else beg = b_mid+1;
      }

      return ret_high-ret_low+1;
}

int quary(int node, int b, int e, int x, int y, int val)
{
      if (b>y || e<x)return 0;
      if (b>=x && e<=y){
            return searchMsortArray(node,val);
      }

      int mid = (b+e)/2;
      return quary(node*2,b,mid,x,y,val)+quary(node*2+1,mid+1,e,x,y,val);
}

void buildSparse()
{
      for (int j=1; (1<<j)<=n ; j++){
            for (int i=1 ; i<=n ; i++){
                  if (sp[i][j-1]==-1)continue;
                  sp[i][j] = sp[sp[i][j-1]][j-1];
            }
      }
}

int find_xth_parent(int u, int x)
{
      for (int j=20 ; j>=0 ; j--){
            if ((1<<j)>x)continue;
            if (sp[u][j]==-1)return -1;
            x-=(1<<j);
            u = sp[u][j];
      }
      return u;
}

int main()
{
      memset(sp,-1,sizeof sp);

      scanf("%d",&n);
      for (int i=1 ; i<=n; i++){
            int a;
            scanf("%d",&a);
            if (a!=0){
                  G[a].push_back(i);
                  sp[i][0] = a;
            }
      }

      for (int i=1 ; i<=n ; i++){
            if (sp[i][0]==-1)eular(i,1);
      }

      N = E.size();

      build(1,0,N-1);
      buildSparse();

      int q;
      scanf("%d",&q);

      while(q--){
            int u,x;
            scanf("%d %d",&u,&x);
            int par = find_xth_parent(u,x);

            if (par==-1)printf("0 ");
            else {
                  int l = start[par],r = finished[par];
                  printf("%d ",quary(1,0,N-1,l,r,L[l]+x)-1);
            }
      }
      printf("\n");


      return 0;
}
