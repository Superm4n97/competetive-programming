#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll A[n+5] , B[n+5];
      for (int i=0 ; i<n ; i++)cin >> A[i];
      for (int i=0 ; i<n ; i++)cin >> B[i];
      ll ans = 0;

      for (int i=0 ; i<n ; i++){
            ans+=(A[i]*B[i]);
      }

      if (ans==0)cout << "Yes" << endl;
      else cout << "No" << endl;


      return 0;
}
