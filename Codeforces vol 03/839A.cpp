#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,k;
      cin >> n >> k;

      ll A[n+5];

      for(int i=1 ;i<=n ; i++)cin >> A[i];

      ll sum = 0 , cnt = -1;

      for (int i=1 ; i<=n ; i++){
            if (A[i]<=8){
                  sum+=A[i];
            }
            else {
                  sum+=8;
                  A[i+1]+=A[i]-8;
            }

            if(sum>=k){
                  cnt = i;
                  break;
            }
      }

      cout << cnt << endl;


      return 0;
}
/**

**/
