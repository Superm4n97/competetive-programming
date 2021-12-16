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
            ll n;
            scl(n);
            vector<ll> v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);
                  v.push_back(a);
            }

            sort(v.begin(),v.end());
            set<ll> st;
            v[n-1]++;
            st.insert(v[n-1]);

            for (int i=n-2 ; i>=0 ; i--){
                  if (v[i]!=v[i+1] && v[i]+1!=v[i+1]){
                        v[i]++;
                  }
                  st.insert(v[i]);
            }
            cout << st.size() << endl;
      }


      return 0;
}
