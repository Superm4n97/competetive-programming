#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll fprev = 0 , tprev = 0, n , ans = 0;
            string s;

            cin >> s;

            n = s.size();

            for (int i=0 ; i<n ; i++){

                  if (s[i]=='(')fprev++;
                  else if (s[i]=='[')tprev++;
                  else if (s[i]==')'){
                        if (fprev>0){
                              ans++;
                              fprev--;
                        }
                  }
                  else {
                        if (tprev>0){
                              ans++;
                              tprev--;
                        }
                  }
            }

            cout << ans << endl;
      }
}
