#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n,t;
            cin >> n >> t;

            ll A[n+5] , C[n+5] , cntA=0 , cntB = 0;
            map < ll , ll > mp;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];

                  if (A[i]+A[i]==t){
                        if (cntA<=cntB){
                              C[i] = 1;
                              cntA++;
                        }
                        else {
                              C[i] = 0;
                              cntB++;
                        }
                  }
                  else {
                        if (mp[A[i]]==0){
                              mp[A[i]] = 1;
                              mp[t-A[i]] = 2;
                        }

                        C[i] = mp[A[i]]-1;
                  }
            }

            for (int i=1 ; i<=n ; i++)cout <<C[i] << " ";
            cout << endl;
      }

      return 0;
}
