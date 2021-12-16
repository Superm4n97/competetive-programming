#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int x[1005],y[1005];
//map<pair<int,int>,int> mp;
vector <pair<int,int> > vp;

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n;
            scanf("%lld",&n);

            for (int i=0 ; i<n ; i++)scanf("%d %d",&x[i],&y[i]);

            for (int i=0 ; i<n ; i++){
                  for (int j=i+1 ; j<n ; j++){
                        //ans+= mp[make_pair(x[i]+x[j],y[i]+y[j])];
                        //mp[make_pair(x[i]+x[j],y[i]+y[j])]++;
                        vp.push_back(make_pair(x[i]+x[j],y[i]+y[j]));
                  }
            }
            sort(vp.begin(),vp.end());

            ll ans = 0 , cnt = 1;
            for (int i=1 ; i<vp.size() ; i++){
                  if (vp[i].first==vp[i-1].first && vp[i].second==vp[i-1].second)cnt++;
                  else {
                        ans+=(cnt*(cnt-1))/2;
                        cnt = 1;
                  }
            }
            ans+=(cnt*(cnt-1))/2;

            printf("Case %d: %lld\n",_t,ans);
            //mp.clear();
            vp.clear();
      }

      return 0;
}
