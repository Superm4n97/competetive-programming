#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

string s,t;
ll n,m;

bool check(ll id)
{
      for (int i=0 ; i<n ; i++){
            if (t[0]==s[i]){
                  bool sol = true;
                  for (int j=0 ; j<=id ; j++){
                        if (i+j>=n || s[i+j]!=t[j]){
                              sol = false;
                              break;
                        }
                  }
                  if (!sol)continue;

                  ll _i = i+id;

                  for (int j=id+1 ; j<m ; j++){
                        ll x = j-id;
                        if (_i-x<0 || s[_i-x]!=t[j]){
                              sol = false;
                              break;
                        }
                  }

                  if (sol)return true;
            }
      }
      return false;
}

bool init()
{
      for (int i=m-1 ; i<n ; i++){
            if (s[i] == t[0]){
                  bool sol = true;
                  for (int j=0 ; j<m ; j++){
                        if (s[i-j]!=t[j]){
                              sol = false;
                              break;
                        }
                  }
                  if (sol)return true;
            }
      }
      return false;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            cin >> s;
            cin >> t;
            n = s.size();
            m = t.size();

            bool ans = init();

            for (int i=0 ; i<m ; i++){
                  if (check(i)){
                        ans = true;
                        break;
                  }
            }

            if (ans)cout << "YES\n";
            else cout << "NO\n";
      }

      return 0;
}
