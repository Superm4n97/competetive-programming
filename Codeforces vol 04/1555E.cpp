#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x);
#define maxn 1000006
#define inf 100000000000000017

using namespace std;

ll n ,m , st[maxn*4], prop[maxn*4];

void relax(ll node, ll b, ll e)
{
      if (prop[node]==0)return;

      if (b==e){
            st[node]+=prop[node];
            prop[node] = 0;
      }
      else {
            st[node]+=prop[node];
            prop[node*2]+=prop[node];
            prop[node*2+1]+=prop[node];
            prop[node] = 0;
      }
}

void rangeUpdate(ll node, ll b, ll e, ll x, ll y, ll val)
{
      relax(node, b, e);
      if (e<x || b>y)return;
      if (x<=b && e<=y){
            prop[node] = val;
            relax(node,b,e);
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      rangeUpdate(L,b,mid,x,y,val);
      rangeUpdate(R,mid+1,e,x,y,val);

      st[node] = min(st[L],st[R]);
      return;
}

ll rangeQuary(ll node, ll b, ll e, ll x, ll y)
{
      relax(node,b,e);
      if (e<x || b>y)return inf;
      if (x<=b && e<=y)return st[node];

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      ll t1 = rangeQuary(L,b,mid,x,y) , t2 = rangeQuary(R,mid+1,e,x,y);

      return min(t1,t2);
}

int main()
{
      scl(n);
      scl(m);
      vector<pair<ll, pair<ll,ll> > > vp;

      for (int i=1 ; i<=n ; i++){
            ll l,r,w;
            scl(l);
            scl(r);
            scl(w);

            //editable
            r--;

            vp.push_back({w,{l,r}});
      }

      //editable
      m--;

      sort(vp.begin(),vp.end());

      ll bg = 0 , ed = -1 , ans = inf;

//      cout << endl;
//      for (int i=0 ; i<n ; i++)cout << vp[i].first << " : " << vp[i].second.first << ","<< vp[i].second.second << endl;

      while(ed<n-1){
            ed++;
            ll L = vp[ed].second.first, R = vp[ed].second.second;
            rangeUpdate(1,1,m,L,R,1);

            while(bg<=ed){
                  ll chk = rangeQuary(1,1,m,1,m);
                  if (chk==0)break;
                  else {
//                        show(bg);
//                        show(ed);
//                        show(chk);
//                        cout << endl;

                        ans = min(ans,vp[ed].first - vp[bg].first);
                        L = vp[bg].second.first, R = vp[bg].second.second;
                        rangeUpdate(1,1,m,L,R,-1);
                        bg++;
                  }
            }
      }
      printf("%lld\n",ans);

      return 0;
}
