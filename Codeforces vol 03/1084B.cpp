#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,k;
      cin >> n >> k;

      ll A[n+5] , sum = 0;

      for (int i=0 ; i<n ; i++){

            cin >> A[i];
            sum+=A[i];
      }

      if (sum<k){
            cout << -1 << endl;
            return 0;
      }

      ll temp = (sum-k)/n;

      for (int i=0; i<n ; i++){
            temp = min(temp,A[i]);
      }

      cout << temp << endl;


      return 0;
}
