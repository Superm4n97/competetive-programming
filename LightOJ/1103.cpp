#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n,m;
vector<pair<ll,ll> > A,B;

/**in a range how many numbers are grater then val**/
vector<ll>mst[4*maxn];
void Merge(ll C, ll L, ll R)
{
      ll x = 0 , y = 0;
      while(x<mst[L].size() || y<mst[R].size()){
            if (y>=mst[R].size()){
                  mst[C].push_back(mst[L][x]);
                  x++;
            }
            else if (x>=mst[L].size()){
                  mst[C].push_back(mst[R][y]);
                  y++;
            }
            else if (mst[L][x]<=mst[R][y]){
                  mst[C].push_back(mst[L][x]);
                  x++;
            }
            else {
                  mst[C].push_back(mst[R][y]);
                  y++;
            }
      }
      return;
}
void build(ll node, ll b, ll e)
{
      mst[node].clear();
      if (b==e){///initialize value: the array
            mst[node].push_back(A[b].second);
            return;
      }
      int mid = (b+e)/2 , L = node*2, R = node*2+1;
      build(L,b,mid);
      build(R,mid+1,e);
      Merge(node,L,R);
      return;
}
ll searchBaseLow(ll node, ll val)
{
      ///mst[node] is the sorted vector lies in the range
      ll b = 0 , e = mst[node].size()-1 , ret = mst[node].size();
      while(b<=e){
            ll mid = (b+e)/2;
            if (mst[node][mid] >= val){
                  e = mid-1;
                  ret = min(ret,mid);
            }
            else b = mid+1;
      }
      return mst[node].size()-ret;
}
ll queryLow(ll node, ll b, ll e, ll rangeL, ll rangeR, ll val)
{
      if (b>rangeR || e<rangeL)return 0;///outside the range
      if (rangeL<=b && rangeR>=e)return searchBaseLow(node,val);

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      ///merging L and R with +
      return queryLow(L,b,mid,rangeL,rangeR,val)+queryLow(R,mid+1,e,rangeL,rangeR,val);
}

ll searchBaseHigh(ll node, ll val)
{
      ///mst[node] is the sorted vector lies in the range
      ll b = 0 , e = mst[node].size()-1 , ret = -1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (mst[node][mid] <= val){
                  b = mid+1;
                  ret = max(ret,mid);
            }
            else e = mid-1;
      }
      return ret+1;
}
ll queryHigh(ll node, ll b, ll e, ll rangeL, ll rangeR, ll val)
{
      if (b>rangeR || e<rangeL)return 0;///outside the range
      if (rangeL<=b && rangeR>=e)return searchBaseHigh(node,val);

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      ///merging L and R with +
      return queryHigh(L,b,mid,rangeL,rangeR,val)+queryHigh(R,mid+1,e,rangeL,rangeR,val);
}

ll searchId(ll val)
{
      ll b = 0 , e = n-1 , ret = -1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (A[mid].first<val){
                  ret = max(ret,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return ret;
}


int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc; _t++){
            A.clear();
            B.clear();

            scanf("%lld %lld",&n,&m);

            for (int i=0 ; i<n ; i++){
                  ll a,b;
                  scanf("%lld %lld",&a,&b);
                  A.push_back({a,b});
            }
            for (int i=0 ; i<m ; i++){
                  ll a,b;
                  scanf("%lld %lld",&a,&b);
                  B.push_back({a,b});
            }
            sort(A.begin(),A.end());
            build(1,0,n-1);

            ll ans = 0;

            for (int i=0 ; i<m ; i++){
                  ll a=B[i].first , b = B[i].second;
                  ll id = searchId(a), cnt = 0;
                  if (id>=0){
                        ans += queryLow(1,0,n-1,0,id,b);
                  }
                  if (id<n-1){
                        ans += queryHigh(1,0,n-1,id+1,n-1,b);
                  }
            }
            printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}
/*
1
2 2
2 1
4 3
1 2
3 4
*/
