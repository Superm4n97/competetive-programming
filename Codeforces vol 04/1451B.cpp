#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,q;
            cin >> n >> q;

            string s;
            cin >> s;

            ll pre[n+4][4] , post[n+4][4];
            memset(pre,0,sizeof pre);
            memset(post,0,sizeof post);

            for (int i=0 ; i<n ; i++){
                  pre[i+1][0] = pre[i][0];
                  pre[i+1][1] = pre[i][1];

                  if (s[i]=='0')pre[i+1][0] = 1;
                  else pre[i+1][1] = 1;
            }
            for (int i=n-1 ; i>=0 ; i--){
                  post[i+1][0] = post[i+2][0];
                  post[i+1][1] = post[i+2][1];

                  if (s[i]=='0')post[i+1][0] = 1;
                  else post[i+1][1] = 1;
            }

            while(q--){
                  ll l,r;
                  cin >> l >> r;

                  ll a = s[l-1]-'0' , b = s[r-1]-'0';

                  bool sol = false;

                  if (pre[l-1][a]==1)sol = true;
                  if (post[r+1][b]==1)sol = true;

                  cout << (sol?"YES":"NO") << "\n";
            }
      }

      return 0;
}
