#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "<< x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,m,k;
            cin >> n >> m >> k;

            ll A[n+5];
            bool solution = true;

            for (int i= 1 ; i<=n ; i++)cin >> A[i];

            for (int i=1 ; i<n ; i++){

                  ll temp = max(0LL,A[i+1]-k);

                  if (temp>=A[i]){
                        m-=(temp - A[i]);
                        if (m<0)solution = false;
                  }
                  else {
                        m+=(A[i] - temp);
                  }
            }

            cout << (solution?"YES":"NO") << endl;
      }


      return 0;
}
