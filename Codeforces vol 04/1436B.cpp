#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,127, 131};
      map <ll,ll> mp;

      for (int i=0 ; i<31 ; i++){
            mp[prime[i]]++;
      }

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5][n+5];

            ll B[n+5];
            for (int i=1;  i<n ; i++){
                  B[i] = 1;
            }
            B[n] = 113-(n-1);

            if (mp[B[n]]){
                  B[n]-=3;
                  B[1] += 3;
            }

            for (int i=1 ; i<=n ; i++){
                  for (int j=i ; j<=n ; j++){
                        cout << B[j] << " " ;
                  }
                  for (int j = 1 ; j<i ; j++)cout << B[j] << " ";
                  cout << "\n";
            }
      }


      return 0;
}
