#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5];

            for (int i=1 ; i<=n ; i++)cin >> A[i];

            ll pre = 0;
            bool sol1 = true , sol2 = true;

            for (int i=2 ; i<=n ; i++){

                  A[i]-=pre;
                  if (A[i]<0){
                        sol1 = false;
                        break;
                  }
                  if (A[i]>A[i-1]){

                        pre+=(A[i]-A[i-1]);
                        A[i] = A[i-1];
                  }
            }
            if (sol1)cout << "YES\n";
            else cout << "NO\n";
      }

      return 0;
}
