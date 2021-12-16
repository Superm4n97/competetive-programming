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

            ll A[n+5] , L[n+5];
            vector < ll > v;

            for (int i=1 ; i<=n ; i++)cin >> A[i];
            for (int i=1 ; i<=n ; i++){
                  cin >> L[i];
                  if (L[i]==0)v.push_back(A[i]);
            }

            if (!v.empty())sort(v.rbegin() , v.rend());

            ll pos = 0;

            for (int i=1 ; i<=n ; i++){

                  if (L[i]==0){
                        A[i] = v[pos];
                        pos++;
                  }
            }

            for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
            cout << endl;

      }


      return 0;
}
