#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x);

using namespace std;
#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x);

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;

            vector<ll> A;
            for (int i=0 ; i<2*n ; i++){
                  ll a;
                  cin >> a;
                  A.push_back(a);
            }
            sort(A.begin(),A.end());

            for (int i=1 ; i<2*n-1 ; i+=2){
                  swap(A[i],A[i+1]);
            }
            for (int i=0 ; i<2*n ; i++)cout << A[i] << " ";
            cout << endl;
      }

      return 0;
}
/*
1 3 2 5 4 7 6
*/
