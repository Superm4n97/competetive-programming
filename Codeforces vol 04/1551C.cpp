#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%lld",&w)
#define show(x)         cout << #x << " : " << x << endl
#define inf             100000000000000017
#define maxn            1000006

using namespace std;

vector<ll> v[10];

void clean()
{
      for (int i=0 ; i<5 ; i++)v[i].clear();
}

void process(string s)
{
      ll cnt[10] , sum = 0;
      memset(cnt,0,sizeof cnt);
      for (int i=0 ; i<s.size() ; i++){
            ll temp = s[i]-'a';
            cnt[temp]++;
            sum++;
      }

      for (int i=0 ; i<5 ; i++){
            v[i].push_back(cnt[i]-(sum-cnt[i]));
      }
}

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;

            clean();

            for (int i=0 ; i<n ; i++){
                  string s;
                  cin >> s;
                  process(s);
            }

            for (int i=0 ; i<5 ; i++){
                  sort(v[i].rbegin(),v[i].rend());
            }

            for (int i=1 ; i<n ; i++){
                  for (int j=0 ; j<5 ; j++){
                        v[j][i]+=v[j][i-1];
                  }
            }

            int ans = 0;

            for (int i=0 ; i<5 ; i++){
                  for (int j=0 ; j<n ; j++){
                        if (v[i][j]>0)ans = max(ans,j+1);
                  }
            }
            cout << ans << endl;
      }

      return 0;
}

/**

*/
