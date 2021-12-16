#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            string s;
            cin >> s;

            ll off = 0 , cw = 0, acw = 0;

            for (int i=0 ; i<n ; i++){
                  if (s[i]=='-')off++;
                  else if(s[i]=='>')cw++;
                  else acw++;
            }

            if (off+cw==n || off+acw==n)cout << n << endl;
            else {

                  set <ll > st;
                  for (int i=0 ;i<n ; i++){
                        if (s[i]=='-'){
                              st.insert(i);
                              st.insert((i+1)%n);
                        }
                  }
                  if (st.empty())cout << 0 << endl;
                  else cout << st.size() << endl;
            }
      }

      return 0;
}
