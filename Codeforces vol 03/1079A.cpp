#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll cnt[105] , mx = 0;
set < ll > st;

int main()
{
      ll n,k;
      cin >> n >> k;

      for (int i=0 ; i<n ; i++){

            ll a;
            cin >> a;
            cnt[a]++;
            mx = max(mx,cnt[a]);
            st.insert(a);
      }

      mx+=(k-1);
      mx/=k;
      mx*=k;


      //show(mx);

      mx*=st.size();



      cout << mx-n << endl;


      return 0;
}
/**

**/
