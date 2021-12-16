#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll numberOfDigit(ll n)
{
      ll cnt = 0;
      while(n){
            cnt++;
            n/=10;
      }
      return cnt;
}

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll x1,p1,x2,p2;
            cin >> x1 >> p1;
            cin >> x2 >> p2;

            ll na = numberOfDigit(x1) , nb = numberOfDigit(x2);

            if (na+p1 > nb+p2)cout << '>' << endl;
            else if (na+p1 < nb+p2)cout << '<' << endl;
            else {
                  if (na<nb){
                        for (int i=0 ; i<nb-na ; i++)x1*=10;
                  }
                  if (na>nb){
                        for (int i=0 ; i<na-nb ; i++)x2*=10;
                  }

                  if (x1>x2)cout << '>' << endl;
                  else if (x1<x2)cout << '<' << endl;
                  else cout << '=' << endl;
            }
      }

      return 0;
}
