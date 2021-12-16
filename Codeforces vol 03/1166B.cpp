#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll k;
string vw = "aeiou" , s;

int main()
{
      cin >> k;
      ll n = -1,  m = -1;

      for (int i=5 ; i<=k ; i++){

            ll temp = k/i;

            if (k%i==0 && temp>=5){
                  n = i;
                  m = temp;
            }
      }

      for (int i=0 ; i<n; i++){
            ll start = i%5;
            for (int j = 0 ; j<m ; j++){
                  start%=5;
                  s+=vw[start];
                  start++;
            }
      }

      if (n==-1){
            cout << -1 << endl;
            return 0;
      }

      /*show(s.size());

      for (int i=0 ; i<s.size() ; i++){
            if (i%n==0)cout << endl;
            cout << s[i] ;
      }
      cout << endl;
      */

      cout << s << endl;


      return 0;
}
