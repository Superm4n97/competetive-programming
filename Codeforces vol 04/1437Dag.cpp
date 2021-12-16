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

            stack <ll> st;
            ll ans = 0;

            for (int i=0  ;i<n ; i++){
                  ll a;
                  cin >> a;

                  while(!st.empty()){

                        if (st.top()>a)break;
                        st.pop();
                  }
                  st.push(a);

                  ans = max(ans,(ll)st.size());
            }

            cout << ans << "\n";
      }

      return 0;
}
