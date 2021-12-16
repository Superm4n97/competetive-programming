#include<bits/stdc++.h>
#define ll long long int
#define maxn 300005
#define inf 10000000000000016

using namespace std;

///   invl       mn mx
pair <ll,pair<ll,ll> > S[maxn*4];
ll A[maxn] , C[maxn] , n , q;
map < ll,ll > rev_mp , mp , cnt;

void build(ll node, ll b, ll e)
{
      if (b==e){
            if (A[b]==1){/**Initial Value assign**/
                  S[node].first = 0;
                  S[node].second.first = b;
                  S[node].second.second = b;
            }
            else {
                  S[node].first = 0;
                  S[node].second.first = inf;
                  S[node].second.second = -inf;
            }
            return;
      }

      ll mid = (b+e)/2;
      build(node*2 , b, mid);
      build(node*2+1 , mid+1, e);

      { /**Merging two childes**/
            S[node].second.first = min(S[node*2].second.first , S[node*2+1].second.first);
            S[node].second.second = min(S[node*2].second.second , S[node*2+1].second.second);

            if (S[node].second.first == S[node*2].second.second) S[node].first = 0;
            else {
                  ll temp = 0;

                  if (S[node*2].second.second != -inf && S[node*2+1].second.first!=inf){
                        temp = rev_mp[S[node*2].second.second] - rev_mp[S[node*2+1].second.first];
                  }
                  S[node].first = max(temp,max(S[node*2+1].first , S[node*2].first));
            }
      }

      return;
}

void update(ll node, ll b, ll e, ll index, ll x)
{
      if(b>index || e<index)return;

      if (b==e){
            {/**Update position**/
                  if (x==0){
                        S[node].first = 0;
                        S[node].second.first = inf;
                        S[node].second.second = -inf;
                  }
                  else {
                        S[node].first = 0;
                        S[node].second.first = b;
                        S[node].second.second = b;
                  }
            }
            return;
      }

      ll mid = (b+e)/2;
      update(node*2,b,mid,index,x);
      update(node*2+1,mid+1,e,index,x);

      { /**Merging two childes**/
            S[node].second.first = min(S[node*2].second.first , S[node*2+1].second.first);
            S[node].second.second = min(S[node*2].second.second , S[node*2+1].second.second);

            if (S[node].second.first == S[node*2].second.second) S[node].first = 0;
            else {
                  ll temp = 0;

                  if (S[node*2].second.second != -inf && S[node*2+1].second.first!=inf){
                        temp = rev_mp[S[node*2].second.second] - rev_mp[S[node*2+1].second.first];
                  }
                  S[node].first = max(temp,max(S[node*2+1].first , S[node*2].first));
            }
      }
      return;
}

/*pair <ll,pair<ll,ll> > query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x){
            //return 0;
      }

      if(b>=x && e<=y){
            return S[node];
      }

      ll mid = (b+e)/2;
      pair <ll,pair<ll,ll> > t1 = query(node*2,b,mid ,x,y);
      pair <ll,pair<ll,ll> > t2 = query(node*2+1,mid+1,e,x,y);

      {

            pair <ll,pair<ll,ll> > t;

            t.second.first = min(t1.second.first , t2.second.first);
            t = min(t1.second.second , t2.second.second);

            if (t.second.first == t.second.second) t.first = 0;
            else {
                  ll temp = 0;

                  if (t1.second.second != -inf && t2.second.first!=inf){
                        temp = rev_mp[t1.second.second] - rev_mp[t2.second.first];
                  }
                  t.first = max(temp,max(t2.first , t1.first));
            }

            return t;
      }
}
*/

int main()
{
      cin >> n >> q;

      vector < ll > v;
      vector < pair < ll,ll > > vp;


      for (int i=1 ; i<=n ; i++){
            cin >> C[i];
            v.push_back(C[i]);
            mp[C[i]]++;
      }


      for (int i=0 ; i<q ; i++){
            ll a,b;
            cin >> a >> b;
            vp.push_back({a,b});

            if (mp[b]==0)v.push_back(b);
      }

      ll id = 1;
      sort(v.begin() , v.end());

      for (int i=0 ; i<v.size() ; i++){

            mp[v[i]] = i+1;
            rev_mp[i+1] = v[i];
      }

      ll N = v.size();

      for (int i=1 ; i<=n ; i++){
            A[mp[C[i]]] = 1;
      }

      build(1,1,N);

      for (int i=0 ; i<q ; i++){
            update(1,1,N,mp[vp[i].second] ,vp[i].first);

            cout << rev_mp[S[1].second.second] - rev_mp[S[1].second.first] - S[1].first << endl;
      }



      return 0;
}
