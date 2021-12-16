#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll k,l,r,t,x,y;
      cin >> k >> l >> r >> t >> x >> y;

      if (y<x){
            ll red = x-y;
            if (k+y>r){
                  k-=x;
                  t--;
            }
            if (k<l){
                  cout << "No" << endl;
                  return 0;
            }
            if (t==0){
                  cout << "Yes" << endl;
                  return 0;
            }

            ll p = (k-l)/red;
            if (p>=t){
                  cout << "Yes" << endl;
                  return 0;
            }
            else cout << "No" << endl;
      }
      else {
            k-=l , r-=l;
            if (x-1+y<=r){
                  cout << "Yes" << endl;
                  return 0;
            }
            ll in = y-x;
            ll temp = (k)/x;
            t-=temp;
            if (t<=0){
                  cout << "Yes" << endl;
                  return 0;
            }
            k = (k)%x;

            temp = k/in;
            t-=temp;

            if (t<=0){
                  cout << "Yes" << endl;
                  return 0;
            }
            cout << "No" << endl;


      }

      return 0;
}
