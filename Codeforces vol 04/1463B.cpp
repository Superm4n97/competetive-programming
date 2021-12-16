#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      ll P[40];
      P[0] = 1;
      for (int i=1 ; i<40 ; i++)P[i] = P[i-1]*2;

      while(tc--){

            ll n;
            cin >> n;
            ll A[n+5];
            for (int i=0 ; i<n ; i++){
                  cin >> A[i];
                  ll l = (A[i]+1)/2 , r = A[i];
                  for (int j = 0 ; j<40 ; j++){
                        if (P[j]>=l && P[j]<=r){
                              A[i] = P[j];
                        }
                  }
            }
            for (int i=0 ; i<n ; i++)cout << A[i] << " ";
            cout << endl;
      }


      return 0;
}
