#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define inf 100000000000000017

using namespace std;

int main()
{
      ll tc;
      scl(tc);
      while(tc--){
            ll n;
            scl(n);

            vector < pair<ll,pair<ll,ll> > >vp;

            ll ans[n+5];

            for (ll i=1;  i<=n ; i++){
                  ll a, b;
                  scl(a),scl(b);
                  if (a<b)swap(a,b);
                  vp.push_back({a,{b,i}});
            }

            sort(vp.rbegin(),vp.rend());

            for (int i=0 ; i<n ; i++){
                  if (vp[i].first>vp[n-1].first && vp[i].second.first>vp[n-1].second.first)
                        ans[vp[i].second.second] = vp[n-1].second.second;
                  else ans[vp[i].second.second] = -1;
            }

            priority_queue<pair<ll,ll> > pq;
            //pq.push(vp[n-1].second.first,vp[n-1].second.second);
            //ans[vp[n-1].second.second] = -1;

            ll i = n-1 , j = n-1;
            while(i>=0LL){
                  while(vp[i].first>vp[j].first){
                        pq.push({vp[j].second.first * -1,vp[j].second.second});
                        j--;
                  }
//                  show(i);
//                  show(j);
                  if (pq.empty())ans[vp[i].second.second] = -1;
                  else {
                        if (pq.top().first*-1<vp[i].second.first){
                              //show(vp[i].second.first);
                              ans[vp[i].second.second] = pq.top().second;
                        }
                  }
                  i--;
            }

            for (int k=1 ; k<=n ; k++)printf("%I64d ",ans[k]);
            printf("\n");
      }

      return 0;
}
