#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

vector<ll> x,y;
vector<pair<ll,ll> > A,B;
ll n,m , k , freX[maxn] , freY[maxn];

void clean()
{
      for (int i=0 ; i<x.size() ; i++)freX[x[i]] = freY[x[i]] = 0;
      for (int i=0 ; i<y.size() ; i++)freX[y[i]] = freY[y[i]] = 0;
      x.clear();
      y.clear();
      A.clear();
      B.clear();
}

ll find_idx_in_x(ll a)
{
      ll b = 0 , ret = -1 , e = x.size()-1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (x[mid]<=a){
                  ret = max(mid,ret);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return ret+1;
}

ll find_idx_in_y(ll a)
{
      ll b = 0 , e = y.size()-1, ret = -1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (y[mid]<=a){
                  ret = max(ret,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return ret+1;
}

ll cal(vector<ll> v)
{
      ll ret = 0, t1=0 , t2=1;
      while(t2<v.size()){
            while(v[t1]<v[t2])t1++;
            ret+=t1;
            t2++;
      }
      return ret;
}

ll count_pair(vector<pair<ll,ll> > vp)
{
      ll ret = 0;
      vector<ll> v;

      if (vp.empty())return 0;

      sort(vp.begin(),vp.end());
      v.push_back(vp[0].second);
      for (int i=1 ; i<vp.size() ; i++){
            if (vp[i].first!=vp[i-1].first){
                  ret += cal(v);
                  v.clear();
                  v.push_back(vp[i].second);
            }
            else {
                  v.push_back(vp[i].second);
            }
      }
      ret+=cal(v);

      return ret;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld %lld %lld",&n,&m,&k);

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  freX[a] = 1;
                  x.push_back(a);
            }
            for (int i=0 ; i<m ; i++){
                  ll a;
                  scanf("%lld",&a);
                  freY[a] = 1;
                  y.push_back(a);
            }
            for (int i=0 ; i<k ; i++){
                  ll a,b;
                  scanf("%lld %lld",&a,&b);
                  if (freX[a]==1 && freY[b]==0){
                        A.push_back({find_idx_in_y(b),a});
                  }
                  if (freX[a]==0 && freY[b]==1){
                        B.push_back({find_idx_in_x(a),b});
                  }
            }

            printf("%lld\n",count_pair(A)+count_pair(B));

            clean();
      }

      return 0;
}
/*
1
2 2 8
2 5
2 5

2 3
2 4
3 2
4 2
5 3
5 4
3 5
4 5

1
2 3 3
2 5
2 5 6

0 2
0 5
0 6


*/
