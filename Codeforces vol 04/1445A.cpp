#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            vector < ll > A,B;
            ll n , x;
            cin >> n >> x;
            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  A.push_back(a);
            }
            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  B.push_back(a);
            }

            sort(A.begin(),A.end());
            sort(B.rbegin(),B.rend());

            bool solution = true;

            for (int i=0 ; i<n ; i++){
                  if (A[i]+B[i]>x){
                        solution = false;
//                        show(A[i]);
//                        show(B[i]);
                  }
            }

            cout << (solution?"Yes":"No") << "\n";
      }

      return 0;
}
