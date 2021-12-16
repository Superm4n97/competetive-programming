#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,x,y , a,b,c,d;
      cin >> n >> x >> y;

      a = b = c = d = 0;

      for (int i=0 ; i<n ; i++){
            ll A,B;
            cin >> A >> B;

            if(B>y)a++;
            if(B<y)b++;
            if(A>x)c++;
            if(A<x)d++;
      }

      ll mx = max(max(a,b),max(c,d));

      cout << mx << endl;

      if (a==mx)cout << x << " " << y+1 << endl;
      else if (b==mx)cout << x << " " << y-1 << endl;
      else if (c==mx)cout << x+1 << " " << y << endl;
      else cout << x-1 << " " << y << endl;


      return 0;
}
