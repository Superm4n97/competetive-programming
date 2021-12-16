#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000000000016
#define maxn 200005
#define ss second
#define ff first

using namespace std;
//           mn mx
pair<ll,pair<ll,ll> > S[maxn*4];
map < ll , ll > index , mp , check;
vector < pair <ll,ll> > vp;
vector < ll > v , Z;
ll n,q,A[maxn] , N;

pair<ll,pair<ll,ll> > nullPair()
{
      pair<ll,pair<ll,ll> > p;
      p.first = 0;
      p.ss.ff = inf;
      p.ss.ss = -inf;

      return p;
}

pair<ll,pair<ll,ll> > mergePairs(pair<ll,pair<ll,ll> > t1 , pair<ll,pair<ll,ll> > t2)
{
      pair<ll,pair<ll,ll> > t;

      t.ff = max(t1.ff , t2.ff);
      t.ss.ff = min(t1.ss.ff,t2.ss.ff);
      t.ss.ss = max(t1.ss.ss , t2.ss.ss);

      if (t1.ss.ss!=-inf && t2.ss.ff!=inf){

            ll b = t1.ss.ss , e = t2.ss.ff;
            t.ff = max(t.ff , v[e]-v[b]);
      }

      return t;
}

void build(ll node, ll b, ll e)
{
      if (b==e){
            if (A[b]==1){
                  S[node].ff = 0;
                  S[node].ss.ff = b;
                  S[node].ss.ss = b;
            }
            else S[node] = nullPair();

            return;
      }

      ll mid = (b+e)/2;
      build(node*2 ,b,mid);
      build(node*2+1,mid+1,e);

      S[node] = mergePairs(S[node*2],S[node*2+1]);

      return;
}

void update(ll node, ll b, ll e, ll id, ll type)///A er id aibo
{
      if (b>id || e<id)return;

      if (b==e){

            if (type==0){
                  S[node] = nullPair();
            }
            else {
                  S[node].ff = 0;
                  S[node].ss.ff = b;
                  S[node].ss.ss = b;
            }

            return;
      }

      ll mid = (b+e)/2;
      update(node*2 ,b,mid,id,type);
      update(node*2+1,mid+1,e,id,type);

      S[node] = mergePairs(S[node*2],S[node*2+1]);

      return;
}

ll calculation()
{
      ll interval = S[1].first;

      if (interval==0)return 0;

      ll b = S[1].ss.ff , e = S[1].ss.ss;
      return v[e] - v[b] - interval;
}

int main()
{
      cin >> n >> q;
      for (int i=0 ; i<n ; i++){
            ll a;
            cin >>a;

            Z.push_back(a);
            v.push_back(a);
            check[a] = 1;
      }

      for (int i=0 ; i<q ; i++){
            ll x, a;
            cin >> x >> a;

            vp.push_back({x,a});
            if (check[a]==0){
                  v.push_back(a);
                  check[a] = 1;
            }
      }
      v.push_back(-1);
      sort(v.begin(),v.end());

      N = v.size()-1;

      for (int i=1 ; i<v.size() ; i++){
            index[v[i]] = i;
            //mp[i] = v[i];
      }

      for (int i=0 ; i<Z.size() ; i++){

            ll id = index[Z[i]];
            A[id] = 1;
      }

      build(1,1,N);

      cout << calculation()<< endl;

      for (int i=0 ; i<vp.size() ; i++){

            update(1,1,N,index[vp[i].second],vp[i].first);
            cout << calculation() << endl;
      }

      return 0;
}
