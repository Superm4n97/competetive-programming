#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll n,x;
      cin >> n >> x;

      ll A[n+5];
      for (int i=0 ; i<n ; i++)cin >> A[i];
      for (int i=0 ; i<n ; i++){
            if (A[i]!=x)cout << A[i] << " ";
      }
      cout << endl;


      return 0;
}
