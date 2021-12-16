#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector < pair <ll,ll> > vp;
string s[100005] , ans;
ll n , sz[100005];

int main()
{
      cin >> n;
      for (int i=1 ; i<=n ; i++){

            cin >> s[i];
            sz[i] = s[i].size();

            ll x;
            cin >> x;

            for (int j = 0 ; j<x ; j++){
                  ll a;
                  cin >> a;

                  vp.push_back({a,i});
            }
      }

      sort(vp.begin(),vp.end());

      ll r = 0;

      for (int i=0 ; i<vp.size() ; i++){
            ll x = vp[i].first , id = vp[i].second;
            ll y = x+sz[id]-1;

            if (y<=r)continue;

            while(r<x-1){
                  ans.push_back('a');
                  r++;
            }

            for (int j = r+1-x ; j<sz[id] ; j++){
                  ans.push_back(s[id][j]);
            }
            r = y;
      }

      cout << ans << endl;

      return 0;
}
/**

r = 3
abc

x = 2 , y = 7
0 1 2 3 4 5
b c d e f g



**/
