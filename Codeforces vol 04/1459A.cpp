#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(w) scanf("%I64d",&w)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            cin >> n;

            ll r = 0 , b = 0;
            string A,B;
            cin >> A;
            cin >> B;
            for (int i = 0 ; i<n ; i++){
                  if (B[i]>A[i])b++;
                  if (B[i]<A[i])r++;
            }

            if (r>b)cout << "RED" << endl;
            else if (b>r)cout << "BLUE" << endl;
            else cout << "EQUAL" << endl;
      }

      return 0;
}
