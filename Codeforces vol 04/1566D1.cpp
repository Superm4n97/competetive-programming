#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll m , n,A[maxn],N;
vector<ll> mst[maxn*4];

void mergechild(ll node, ll L, ll R)
{
      ll x = 0 , y = 0;
      while(x<mst[L].size() || y<mst[R].size()){
            if (x>=mst[L].size()){
                  mst[node].push_back(mst[R][y]);
                  y++;
            }
            else if (y>=mst[R].size()){
                  mst[node].push_back(mst[L][x]);
                  x++;
            }
            else {
                  if (mst[L][x]<=mst[R][y]){
                        mst[node].push_back(mst[L][x]);
                        x++;
                  }
                  else {
                        mst[node].push_back(mst[R][y]);
                        y++;
                  }
            }
      }
}

void build(ll node, ll b, ll e)
{
      mst[node].clear();
      if (b==e){
            mst[node].push_back(A[b]);
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;

      build(L,b,mid);
      build(R,mid+1,e);

      mergechild(node, L,R);
}

ll bs(ll node, ll val)
{
      ll b = 0 , e = mst[node].size()-1 , ret = -1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (mst[node][mid]<=val){
                  ret = max(ret,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return ret+1;
}

ll query(ll node, ll b, ll e, ll x, ll y, ll val)
{
      if (b>=x && e<=y){
            return bs(node,val);
      }
      if (b>y || e<x)return 0;

      ll mid = (b+e)/2 , L = node*2 , R = node*2+1;

      return query(L,b,mid,x,y,val)+query(R,mid+1,e,x,y,val);
}

int main()
{
      ll tc;
      scanf("%lld",&tc);

      while(tc--){
            scanf("%lld %lld",&n,&m);

            vector<pair<ll,ll> >v;
            for (int i=1 ; i<=n*m ; i++){
                  ll a;
                  scanf("%lld",&a);
                  v.push_back({a,i});
            }

            N = n*m;

            sort(v.begin(),v.end());
            for (int i=0 ; i<n ; i++){
                  ll x = i*m+1 , y = (i+1)*m;
                  priority_queue<pair<ll,ll> > pq;
                  for (int j=x-1 ; j<y ; j++){
                        pq.push({-v[j].first,v[j].second});
                  }

                  ll temp = i*m+1;
                  while(!pq.empty()){
                        ll id = pq.top().second;
                        pq.pop();
                        A[id] = temp;
                        temp++;
                  }
            }


//            cout << " A : ";for (int i=1 ; i<=N ; i++)cout << A[i] << " ";
//            cout << endl;

            build(1,1,N);

            ll ans = 0;
            for (int i=2 ; i<=n*m ; i++){
                  ll r = i-1 , l = 1 , x = (A[i]-1)/m * m + 1 , y = ((A[i]-1)/m+1)*m;
                  ans+=(query(1,1,N,l,r,A[i])-query(1,1,N,l,r,x-1));
            }

            printf("%lld\n",ans);
      }

      return 0;
}
