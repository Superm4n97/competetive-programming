#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n,m;
            scl(n) , scl(m);

            ll cnt[n+5][28];
            memset(cnt,0,sizeof cnt);
            string s[n+5];
            for (int i=0 ; i<n ; i++)cin >> s[i];

            for (int i=0 ; i<n ; i++){
                  for (int j=0; j<m ; j++){
                        ll temp = s[i][j] - 'a';
                        cnt[j][temp]++;
                  }
            }
            for (int i=0 ; i<n-1 ; i++){
                  string st;
                  cin >> st;
                  for (int j = 0 ; j<m ; j++){
                        ll temp = st[j] - 'a';
                        cnt[j][temp]--;
                  }
            }
            string ans = "";
            for (int i=0 ; i<m ; i++){
                  for (int j=0 ; j<26 ; j++){
                        if (cnt[i][j]==1){
                              ans.push_back(char('a'+j));
                              break;
                        }
                  }
            }
            cout << ans << endl;
            fflush(stdout);
      }

      return 0;
}
