#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,x;

bool rec()
{
      if (x==0 || a==x || b==x)return true;
      if (a<x || b==0)return false;
      if ((a-x)%b==0)return true;

      a = a - ((a-b + b)/b)*b;
      swap(a,b);
      return rec();
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            cin >> a >> b >> x;
            if (a<b)swap(a,b);
            if (rec())cout << "YES" << endl;
            else cout << "NO" << endl;
      }

      return 0;
}
