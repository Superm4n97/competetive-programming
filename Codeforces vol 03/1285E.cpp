#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll mx= 50 , id;

int main()
{
      ll A[12];
      A[0] = 12;
      A[1] = 3;
      A[2] = 11;


      for (int i=0 ; i<=15 ; i++){
            ll mn = -1;
            for (int j = 0 ; j<3 ; j++){
                  ll temp = A[j]^i;
                  mn = max(mn,temp);
            }
            if (mn<mx){
                  mx = mn;
                  id = i;
            }
      }

      cout << mx << " " << id << endl;


      return 0;
}
