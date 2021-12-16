#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int l = 1, r = 1000000;
      while (l != r) {
            int mid = (l + r + 1) / 2;


            cout << mid << endl;
            fflush(stdout);
            string s;
            cin >> s;

            if (s == "<")
                  r = mid - 1;
            else
                  l = mid;
      }

      printf("! %d\n", l);
      fflush(stdout);

      return 0;
}
