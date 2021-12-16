#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000

using namespace std;

ll dp[1005][1005], n,k;
vector<pair<pair<ll,ll> , ll> > vp;
vector<ll> ans;

ll rec(ll pos, ll pre)
{
      if (dp[pos][pre] != -1) return dp[pos][pre];
      if (pos==n)return dp[pos][pre] = 0;

      if (vp[pre].first.second<vp[pos].first.second && vp[pre].first.first<vp[pos].first.first){
            ll t1 = rec(pos+1,pre) , t2 = rec(pos+1,pos)+1;
            return dp[pos][pre] = max(t1,t2);
      }
      else return dp[pos][pre] = rec(pos+1,pre);
}

void path(ll pos, ll pre)
{
      if (pos==n)return;
      if (vp[pre].first.second<vp[pos].first.second && vp[pre].first.first<vp[pos].first.first){
            if (dp[pos+1][pre]>dp[pos+1][pos]+1)path(pos+1,pre);
            else {
                  ans.push_back(vp[pos].second);
                  path(pos+1,pos);
            }
      }
      else path(pos+1,pre);
}

int main()
{
      ll w,s,id = 1;
      vp.push_back({{0,-100005},0});
      while(scanf("%lld %lld",&w,&s) != EOF){
            vp.push_back({{w,-s},id});
            id++;
      }
      n = vp.size();
      sort(vp.begin(),vp.end());
      memset(dp,-1,sizeof dp);
      ll cnt = rec(1,0);
      path(1,0);

//      cout << endl;
//      for (int i=0 ; i<vp.size() ; i++)cout << vp[i].first.first << " " << vp[i].first.second << " " << vp[i].second << endl;

      cout << ans.size() << endl;
      for (int i=0 ; i<ans.size() ; i++)cout << ans[i] << endl;


      return 0;
}
/*
1000 4000
1100 3000
2000 1900
8000 1400
*/
