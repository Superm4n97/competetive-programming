#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n , t = 0 , o = 0;
      cin >> n;

      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a;
            if (a&1)o++;
            else t++;
      }

      if (t){
            cout << "2 ";
            t--;
      }
      if (o){
            cout << "1 ";
            o--;
      }

      for (int i=0 ; i<t ; i++)cout << "2 ";
      for (int i=0 ; i<o ; i++)cout << "1 ";
      cout << endl;

      return 0;
}
