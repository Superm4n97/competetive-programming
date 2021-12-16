#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll neg = 0 , pos = 0;

      for (int i=0 ; i<n; i++){
            ll a;
            cin >> a;
            if (a%2){
                  if (a<0){
                        if (neg){
                              a--;
                              a/=2;
                        }
                        else {
                              a/=2;
                        }
                        neg = 1-neg;
                  }
                  else {
                        if (pos){
                              a++;
                              a/=2;
                        }
                        else {
                              a/=2;
                        }
                        pos = 1-pos;
                  }
            }
            else a/=2;

            cout << a << endl;
      }


      return 0;
}
