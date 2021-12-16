#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll A[maxn] , n , stxL[maxn*4] , stxR[maxn*4], styL[maxn*4] , styR[maxn*4] , D[maxn];
vector < ll > G[maxn];

ll findIndexLeft(ll node, ll b, ll e, ll x, ll y, ll type)
{
      if (b>y || e<x)return -1;
      if (b>=x && e<=y){
            if (type==1)return stxL[node];
            else return styL[node];
      }
      ll mid = (b+e)/2;

      return max(findIndexLeft(node*2,b,mid,x,y,type),findIndexLeft(node*2+1,mid+1,e,x,y,type));
}

ll findindexRight(ll node, ll b, ll e, ll x, ll y, ll type)
{
      if (b>y || e<x)return n+5;
      if (b>=x && e<=y){
            if (type==1){
                  if (stxR[node]==-1)return n+5;
                  else return stxR[node];
            }
            else {
                  if (styR[node]==-1)return n+5;
                  else return styR[node];
            }
      }

      ll mid = (b+e)/2;
      return min(findindexRight(node*2,b,mid,x,y,type) ,findindexRight(node*2+1,mid+1,e,x,y,type));
}

void updateIndex(ll node, ll b, ll e, ll index , ll type)
{
      if (b>index || e<index)return;
      if (b==index && e==index){
            if(type==1) stxL[node] = stxR[node] = index;
            else styL[node] = styR[node] = index;
            return;
      }

      ll mid = (b+e)/2;
      updateIndex(node*2,b,mid,index,type);
      updateIndex(node*2+1,mid+1 , e,index,type);

      if (type==1){
            stxL[node] = max(stxL[node*2],stxL[node*2+1]);
            if (stxR[node*2]==-1)stxR[node] = stxR[node*2+1];
            else if (stxR[node*2+1]==-1)stxR[node] = stxR[node*2];
            else stxR[node] = min(stxR[node*2+1] , stxR[node*2]);
      }
      else {
            styL[node] = max(styL[node*2],styL[node*2+1]);
            if (styR[node*2]==-1)styR[node] = styR[node*2+1];
            else if (styR[node*2+1]==-1)styR[node] = styR[node*2];
            else styR[node] = min(styR[node*2+1] , styR[node*2]);
      }
      return;
}

int main()
{
      memset(stxL,-1,sizeof stxL);
      memset(styL,-1,sizeof styL);
      memset(stxR,-1,sizeof stxR);
      memset(styR,-1,sizeof styR);

      vector < pair<ll,ll> > va,vb;
      cin >> n;
      for (int i=1 ; i<=n ; i++){
            cin >> A[i];
            va.push_back({A[i],i});
            vb.push_back({A[i],i});
      }

      for (int i=2 ; i<=n ;i++)G[i].push_back(i-1);

      sort(va.begin(),va.end());
      sort(vb.rbegin(),vb.rend());

      ll l = va[0].second ,r = va[1].second;
      if (l>r)swap(l,r);
      G[r].push_back(l);
      updateIndex(1,1,n,l,1);
      updateIndex(1,1,n,r,1);
      for(int i=2 ; i<n ; i++){

            ll id = va[i].second;
            if (id<l){
                  G[l].push_back(id);
                  l = id;
            }
            else if (id>r){
                  G[id].push_back(r);
                  r = id;
            }
            else {
                  ll p = -1 , q = -1;

                  if (id>1) p = findIndexLeft(1,1,n,1,id-1,1);
                  if (id<n) q = findindexRight(1,1,n,id+1,n,1);

                  updateIndex(1,1,n,id,1);

                  if (p>0 && p<=n) G[id].push_back(p);
                  if (q>0 && q<=n) G[q].push_back(id);
            }
      }


      l = vb[0].second ,r = vb[1].second;
      if (l>r)swap(l,r);
      G[r].push_back(l);
      updateIndex(1,1,n,l,2);
      updateIndex(1,1,n,r,2);
      for(int i=2 ; i<n ; i++){

            ll id = vb[i].second;
            if (id<l){
                  cout << "1 " << id << " " << l << endl;

                  G[l].push_back(id);
                  l = id;
            }
            else if (id>r){
                  cout << "2 " <<  r << " " << id << endl;

                  G[id].push_back(r);
                  r = id;
            }
            else {
//            show(i);
//            show(id);
//            show(l);
//            show(r);
                  ll p = -1 , q = -1;

                  if (id>1) p = findIndexLeft(1,1,n,1,id-1,2);
//                  show(p);
                  if (id<n) q = findindexRight(1,1,n,id+1,n,2);
//                  show(q);

                  cout << "3 " << p << " " << id << " " << q << endl;

                  updateIndex(1,1,n,id,2);

                  if (p>0 && p<=n) G[id].push_back(p);
                  if (q>0 && q<=n) G[q].push_back(id);
            }
      }


      D[1] = 0;
      for (int i=2 ; i<=n ; i++){

            D[i] = n+5;
            for (int j=0 ; j<G[i].size() ; j++){

                  ll v = G[i][j];
                  D[i] = min(D[i],D[v]+1);
            }
      }

      cout << D[n] <<"\n";


      return 0;
}
/**
1 2 3 4 5 6 7 8 9
9
1 2 3 1 4 1 2 3 6
3

1 4
4 6
5 9
3 5

11
1 2 2 3 3 4 1 1 2 3 6

10
4 1 1 1 4 5 5 5 5 4

11
1 3 3 5 2 4 1 2 2 2 5

11
7 7 7 7 7 3 4 3 5 4 5

11
5 4 5 3 4 3 7 7 7 7 7


**/
