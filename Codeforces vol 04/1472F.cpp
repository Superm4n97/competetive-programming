#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n , m;
            scanf("%I64d %I64d",&n,&m);
            vector<pair<ll,ll> > vp;

            for (int i=0 ; i<m ; i++){
                  ll a,b;
                  scanf("%I64d %I64d",&a,&b);
                  vp.push_back({b,a});
            }
            vp.push_back({n+1,1});
            vp.push_back({n+1,2});

            sort(vp.begin(),vp.end());

            bool sol = true , polish = true;

            for (int i=0 ; i<m ; i++){
                  if (vp[i].first==vp[i+1].first){
                        if (!polish)sol = false;
                        i++;
                        continue;
                  }
                  if (polish){
                        polish = false;
                  }
                  else {
//                        show(i);
//                        show(vp[i].first);
//                        show(vp[i].second);

                        if (vp[i-1].second == vp[i].second){
                              //show(vp[i].first - vp[i-1].first);
                              if ((vp[i].first - vp[i-1].first)%2==0)sol = false;
                        }
                        else {
                              if ((vp[i].first - vp[i-1].first)%2)sol = false;
                        }
                        polish = true;
                  }
            }
            if (!polish)sol = false;
            if (sol)printf("YES\n");
            else printf("NO\n");
      }

      return 0;
}
