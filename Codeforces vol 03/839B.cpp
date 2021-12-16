#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,k;
      cin >> n >> k;

      ll A[k+5];

      ll four = n;

      for (int i=1 ; i<=k ; i++){

            cin >> A[i];
            ll temp = min(four,A[i]/4);

            A[i]-=temp*4;
            four-=temp;
      }

      for (int i=1 ; i<=k ; i++){
            if (four && A[i]==3){
                  four--;
                  A[i] = 0;
            }
      }

      //show(four);
      //for (int i=1 ; i<=k ; i++)cout << A[i] << " ";
      //cout << endl;

      ll pairs = 2*n+four , solo = four , need = 0;

      for(int i=1 ; i<=k ; i++){

            ll temp = min(pairs , A[i]/2);
            A[i]-=temp*2;
            pairs-=temp;
      }

      solo += pairs;

      ll sum = 0;

      for (int i=1;i<=k ; i++){
            sum+=A[i];
      }

      if (sum>solo)cout << "NO" << endl;
      else cout << "YES" << endl;


      return 0;
}
/**

**/
