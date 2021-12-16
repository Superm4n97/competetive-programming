#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

void Z_function(string s , ll Z[])
{
      ll N = s.size();

      Z[0] = 0;

      for (int i=1, L = 0 , R = 0 ; i<N ; i++){
            if (i>R){
                  L = R = i;
                  while(R<N && s[R]==s[R-L])R++;
                  R--;
                  Z[i] = R-L+1;
            }
            else {
                  if (i+Z[i-L]-1 < R)Z[i] = Z[i-L];
                  else {
                        L = i;
                        while(R<N && s[R]==s[R-L])R++;
                        R--;
                        Z[i] = R-L+1;
                  }
            }
      }
}

int main()
{
      string s;
      cin >> s;

      ll n = s.size();
      ll Z[n+5];

      Z_function(s,Z);


      vector <ll> v;
      vector<pair<ll,ll> > ans;

      for (int i=0 ; i<n ; i++){
            if (Z[i]>0)v.push_back(Z[i]);
      }

      sort(v.begin(),v.end());

      for (int i=1 ; i<n ; i++){
            if (Z[n-i]==i){
                  ll b = 0 , e = v.size()-1 , res = v.size();
                  while(b<=e){
                        ll mid = (b+e)/2;
                        if (v[mid]>=i){
                              res = min(res,mid);
                              e = mid-1;
                        }
                        else b = mid+1;
                  }
                  res = v.size()-res;

                  ans.push_back({i,res+1});
            }
      }
      ans.push_back({n,1});

      cout << ans.size() << "\n";
      for (int i=0 ; i<ans.size() ; i++)cout << ans[i].first << " " << ans[i].second << "\n";


      return 0;
}
