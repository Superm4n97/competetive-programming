#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      string s;
      cin >> s;

      ll a = 0 , b = 0;

      for (int i=0 ; i<n; i++){
            if (s[i]=='L')a++;
            else b++;
      }
      cout << a+b+1 << endl;

      return 0;
}
