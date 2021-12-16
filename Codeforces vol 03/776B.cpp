#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2000005

using namespace std;

ll mask[maxn] , n;

int main()
{
      cin>> n;

      if (n<=2){
            cout << 1 << endl;
            if (n==1)cout << 1 << endl;
            else cout << 1 << " " << 1 << endl;
      }
      else {
            cout << 2 << endl;
            for (ll i=2 ; i<=n+2;i++){
                  if (mask[i]==0){
                        for (ll j = i*i ; j<=n+2 ; j+=i)mask[j] = 1;
                  }
            }
            for (ll i=2 ; i<=n+1 ; i++)cout << mask[i]+1 << " ";
            cout << endl;
      }


      return 0;
}
