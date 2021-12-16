#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            ll b[n+5], x[n+1] , sum = 0;
            for (int i=0 ; i<n ; i++){
                  cin >> b[i];
                  sum+=b[i];
            }
            ll temp = (n*(n+1))/2;
            if (sum%temp != 0){
                  cout << "NO" << endl;
                  continue;
            }

            ll sumOfAi = sum/temp;

            bool sol = true;

            for (int i=0 ; i<n ; i++){
                  ll p = i-1;
                  if (i==0)p = n-1;

                  x[i] = sumOfAi - (b[i] - b[p]);
                  if (x[i]%n!=0 || x[i]<=0)sol = false;
                  x[i]/=n;

            }
            if (!sol)cout << "NO" << endl;
            else {
                  cout << "YES" << endl;
                  for (int i=0 ; i<n ; i++)cout << x[i] << " ";
                  cout << endl;
            }
      }

      return 0;
}
