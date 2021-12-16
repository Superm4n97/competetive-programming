#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x);

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;

            ll A[n+5];
            for (int i=1 ; i<=n ; i++)cin >> A[i];

            for (int i=2 ; i<n ; i++){
                  if ((A[i-1]+A[i+1])%2==0 && (A[i-1]+A[i+1])/2==A[i])swap(A[i],A[i+1]);
            }
            for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
            cout << endl;
      }

      return 0;
}
