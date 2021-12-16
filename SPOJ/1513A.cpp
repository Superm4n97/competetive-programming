#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n, k;
            cin >> n >> k;
            if (k>(n-1)/2)cout << -1 << endl;
            else {
                  ll A[n+5] , cnt = n;
                  memset(A,0,sizeof A);

                  for (int i=1 ,_k = 1;_k<=k ; i+=2,_k++){
                        A[i] = cnt;
                        cnt--;
                  }
                  for (int i=0 ; i<n ; i++){
                        if (A[i]==0){
                              A[i] = cnt;
                              cnt--;
                        }
                  }
                  for (int i=0 ; i<n ; i++)cout << A[i] << " ";
                  cout << endl;
            }
      }

      return 0;
}
