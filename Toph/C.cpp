#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc = 1 , pw = 1 , sum = 0 , n;
      cin >> n;

      while (tc<=43) {
            cout << "1 " << tc << endl;
            fflush(stdout);

            ll res;
            cin >> res;

            sum+=(n-res)*pw;

            pw*=2;
            tc++;
      }

      cout << "0 " << sum << endl;
      string s;
      cin >> s;
      fflush(stdout);

      return 0;
}
