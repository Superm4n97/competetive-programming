#include<bits/stdc++.h>
#define maxn 100005
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll X,Y,H,V , ans = 1;
vector<pair<ll,ll> >vp;
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
      if (b==e){///initialize value: the array
            mst[node].push_back(vp[b].second);
            return;
      }

      int mid = (b+e)/2 , L = node*2, R = node*2+1;
      build(L,b,mid);
      build(R,mid+1,e);
      Merge(node,L,R);
      return;
}

ll searchBase(ll node, ll val)
{
      ///mst[node] is the sorted vector lies in the range
      ll b = 0 , e = mst[node].size()-1 , ret = mst[node].size();
      while(b<=e){
            ///lower bound
            ll mid = (b+e)/2;
            if (mst[node][mid] > val){
                  e = mid-1;
                  ret = min(ret,mid);
            }
            else b = mid+1;
      }
      return mst[node].size() - ret;
}

ll query(ll node, ll b, ll e, ll rangeL, ll rangeR, ll val)
{
      if (b>rangeR || e<rangeL)return 0;
      if (rangeL<=b && rangeR>=e)return searchBase(node,val);

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      return query(L,b,mid,rangeL,rangeR,val)+query(R,mid+1,e,rangeL,rangeR,val);
}

ll cut(ll a, ll i)
{
      if (i==0)return 0;
      return query(1,0,vp.size()-1,0,i-1,a);
}

int main()
{
      scanf("%lld %lld %lld %lld",&X,&Y,&H,&V);

      ans = (H+1)*(V+1);

      for (int i=0 ; i<H ; i++){
            ll a, b;
            scanf("%lld %lld",&a,&b);
            vp.push_back({a,b});
      }
      sort(vp.begin(),vp.end());

      build(1,0,vp.size()-1);
      for (ll i=0 ; i<H ; i++){
            ans += cut(vp[i].second,i);
      }

      vp.clear();
      cleanMST();


      for (ll i=0 ; i<V ; i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            vp.push_back({a,b});
      }
      sort(vp.begin(),vp.end());

      build(1,0,vp.size()-1);
      for (ll i=0 ; i<V ; i++){
            ans+= cut(vp[i].second,i);
      }

      cout << ans << "\n";

      return 0;
}
