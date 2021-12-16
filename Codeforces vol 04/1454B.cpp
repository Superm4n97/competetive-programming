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

            ll A[n+5] , cnt[n+5];
            memset(cnt , 0 , sizeof cnt);

            for (int i=1 ; i<=n ; i++){

                  cin >> A[i];
                  cnt[A[i]]++;
            }

            ll ans = n+5 , id = -1;
            for (int i=1 ; i<=n ; i++){
                  if (cnt[A[i]]==1 && A[i]<ans){
                        id = i;
//                        show(i);
//                        show(A[i]);
                        ans = A[i];
                  }
            }

            cout << id << endl;
      }

      return 0;
}
