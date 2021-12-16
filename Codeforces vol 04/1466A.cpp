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
            ll A[n+6];
            set <ll> st;

            for (int i=0 ; i<n ; i++){
                  scl(A[i]);
            }
            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<n ; j++){
                        ll temp = abs(A[i]-A[j]);
                        if (temp)st.insert(temp);
                  }
            }
            cout << st.size() << endl;
      }


      return 0;
}
