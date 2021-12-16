#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int char2int(char ch)
{
      return ch-'A';
}

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;
            string s;
            cin >> s;

            ll cnt[30] , ans = 1;
            memset(cnt,0,sizeof cnt);

            cnt[char2int(s[0])] = 1;

            for (int i=1 ; i<n ; i++){
                  if (s[i]!=s[i-1] && cnt[char2int(s[i])]!=0)ans = 0;
                  cnt[char2int(s[i])]++;
            }
            if (ans)cout << "YES\n";
            else cout << "NO\n";
      }

      return 0;
}
