#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int

using namespace std;

ll A[100005];

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n , pos = 0 , deleted = 0;
            cin >> n;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];

                  if (A[i]>0)pos+=A[i];
                  else {
                        ll temp = min(pos , -A[i]);
                        pos-=temp;
                        A[i]+=temp;
                  }
            }

            for (int i=1 ; i<=n ; i++){
                  if (A[i]<0)deleted+=A[i];
            }

            cout << -deleted << endl;

      }


      return 0;
}
