#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "  << x << endl
#define maxn 200005
#define mod  998244353

using namespace std;

ll A[maxn];

int main()
{
      A[1] = 10;

      for (int i=2 ; i<maxn ; i++){

            A[i] = A[i-1]*9;
            A[i]%=mod;
      }

      for (int i=1 ; i<=maxn ; i++){
            A[i]*=i;
            A[i]%=mod;
      }

      for (int i=2 ; i<maxn ;i++){
            A[i]+=A[i-1];
            A[i]%=mod;
      }

      ll n;
      cin >> n;

      for (int i=n; i>=1 ; i--){

            cout << A[i] << " ";
      }
      cout << endl;


      return 0;
}
