#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){

            string s,t,res;
            bool sol = true;

            cin >> s >> t;
            ll i = 0 , j = 0 , n = s.size() ,m =  t.size();
            while(true){
                  if (s[i]!=t[j]){
                        sol = false;
                        break;
                  }
                  res.push_back(s[i]);
                  i++ , j++;
                  if (i==n && j==m)break;
                  if (i==n)i=0;
                  if (j==m)j=0;
            }

            if (!sol)cout << -1 << "\n";
            else cout << res << "\n";
      }

      return 0;
}
