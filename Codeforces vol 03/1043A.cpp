#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll sum = 0 , mx = 0 , n,A[200] , op = 0;

      cin >> n;

      for (int i=0 ; i<n ; i++){

            cin >> A[i];
            mx = max(A[i],mx);
            op+=A[i];
      }

      for (int i=0 ; i<n ; i++)sum += (mx-A[i]);
      ll cnt = 0;

      while(sum<=op){
            mx++;
            sum+=n;
      }

      cout << mx << endl;


      return 0;
}
