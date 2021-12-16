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
            ll A[n+5];
            for (int i=1 ; i<=n ; i++)cin >> A[i];
            vector <ll> v;
            for (int i = 1 ; i<=(n+1)/2 ; i++){
                  v.push_back(A[i]);
                  if (n-i+1 > i)v.push_back(A[n-i+1]);
            }
            for (int i=0 ; i<n ; i++)cout << v[i] << " ";
            cout << endl;
      }

      return 0;
}
