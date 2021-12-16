#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,m;
      cin >> n >> m;
      vector < ll > A,B;

      A.push_back(-1);

      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a;
            A.push_back(a);
      }
      for (int i=0 ; i<m ; i++){
            ll a;
            cin >> a;
            B.push_back(a);
      }

      A.push_back(500);

      if (B.size()>1)cout << "Yes" << endl;
      else {
            bool sol = true;
            for (int i=1 ; i<=n ; i++){
                  if (A[i]==0)A[i] = B[0];
            }

            for (int i=1 ; i<=n ; i++){
                  if (A[i-1]>A[i] || A[i]>A[i+1])sol = false;
            }

            if (sol)cout << "No" << endl;
            else cout << "Yes" << endl;
      }


      return 0;
}
