#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n , S[maxn*4] , A[maxn];

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            vector < pair < ll , ll > > vp;

            cin >> n;
            for (int i=0 ; i<=n+1 ; i++)S[i] = -1;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  if (S[A[i]]==-1)S[A[i]] = i;
                  else {
                        vp.push_back({S[A[i]],i});
                        S[A[i]] = i;
                  }
            }

            //show(n);

            if (!vp.empty())sort(vp.begin(),vp.end());

            ll ans = -1;

            //show(vp.size());

            if (vp.size()==1)ans = vp[0].second - vp[0].first+1;

            for (int i=0 ; i<(int)vp.size() ; i++){
                  //show("check");
                  //show(vp.size());
                  //show(i);

                  //show(vp[i].first);
                  //show(vp[i].second);

                  if (i==vp.size()-1){
                        if (ans==-1)ans = vp[i].second - vp[i].first+1;
                        else ans = min(ans,vp[i].second - vp[i].first+1);
                  }
                  else {
                        if (vp[i].first<vp[i+1].first && vp[i].second>vp[i+1].second){

                        }
                        else {
                              if (ans == -1)ans = vp[i].second-vp[i].first+1;
                              else ans = min(ans,vp[i].second-vp[i].first+1);
                        }
                  }
            }

            //show(ans);

            cout << ans << endl;
      }


      return 0;
}
