#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

struct data
{
      ll prefix,suffix,solution,whole;
} st[4*maxn];
ll n,q,A[maxn];

data cleanNode()
{
      data ret;
      ret.prefix=ret.suffix=ret.solution=ret.whole = 0;
      return ret;
}

ll cal(ll x)
{
      return x*(x+1)/2;
}

data mergeNodes(data x, data y,ll mid)
{
      data ret = cleanNode();

      if (A[mid]<=A[mid+1]){
            if (x.whole)ret.prefix = x.whole+y.prefix;
            else ret.prefix = x.prefix;

            if (y.whole)ret.suffix = y.whole+x.suffix;
            else ret.suffix = y.suffix;

            if (x.whole && y.whole)ret.whole = x.whole+y.whole;

            ret.solution = x.solution+y.solution;
            ll temp = x.suffix+y.prefix;
            if (x.whole==0 && y.whole==0)ret.solution += (temp*(temp+1))/2;
      }
      else {
            ret.prefix = x.prefix;
            ret.suffix = y.suffix;

            ret.solution = x.solution+y.solution;
            if (x.whole==0)ret.solution += (x.suffix*(x.suffix+1))/2;
            if (y.whole==0)ret.solution += (y.prefix*(y.prefix+1))/2;
      }

      return ret;
}

void build(ll node, ll b, ll e)
{
      st[node] = cleanNode();

      if (b==e){
            st[node].prefix = 1;
            st[node].suffix = 1;
            st[node].whole = 1;
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;

      build(L,b,mid);
      build(R,mid+1,e);
      st[node] = mergeNodes(st[L],st[R],mid);
}

void update(ll node, ll b, ll e, ll id, ll val)
{
      if (b==e && b==id){
            A[id] = val;
            return;
      }
      if (b>id || e<id)return;

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      update(L,b,mid,id,val);
      update(R,mid+1,e,id,val);

      st[node] = mergeNodes(st[L],st[R],mid);
      return;
}

data query(ll node, ll b, ll e, ll l, ll r)
{
      if (b>=l && e<=r)return st[node];
      if (b>r || e<l){
            data ret = cleanNode();
            ret.whole = -1;
            return ret;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      data t1 = query(L,b,mid,l,r) , t2 = query(R,mid+1,e,l,r);
      if (t1.whole==-1)return t2;
      if (t2.whole==-1)return t1;
      return mergeNodes(t1,t2,mid);
}

int main()
{
      scanf("%lld %lld",&n,&q);
      for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);

      build(1,1,n);

      while(q--){
            ll type , l,r;
            scanf("%lld %lld %lld",&type,&l,&r);
            if (type==1){
                  update(1,1,n,l,r);
            }
            else {
                  data rt = query(1,1,n,l,r);
                  if (rt.whole==0){
                        ll ans = rt.solution;
                        ans += cal(rt.prefix)+cal(rt.suffix);
                        printf("%lld\n",ans);
                  }
                  else {
                        printf("%lld\n",cal(rt.whole));
                  }
            }
      }


      return 0;
}
