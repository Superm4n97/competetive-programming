#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n , A[105] , mp[1000006] , sum = 0;
string s;

int main()
{
      cin >> n;
      cin >> s;

      for (int i=0 ; i<n ; i++){
            A[i+1] = s[i] - '0';
            sum+=A[i+1];
            mp[sum] = 1;
      }

      if (sum==0){
            cout << "YES" << endl;
            return 0;
      }

      for (ll i=1 ; i<sum; i++){
            if (sum%i==0){

                  ll temp = i;
                  bool sol = true;

                  while(temp<sum){
                        //show(temp);
                        //show(mp[temp]);
                        if(mp[temp]==0)sol = false;
                        temp+=i;
                  }

                  if (sol){
                        //show(i);

                        cout << "YES" << endl;
                        return 0;
                  }
            }
      }

      cout << "NO" << endl;


      return 0;
}


/**

.5 * h * w = m*n / k;
k*h*w = 2*m*n

**/
