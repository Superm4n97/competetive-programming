#include<bits/stdc++.h>

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            int n, k;
            cin >> n >> k;

            string s;
            cin >> s;

            bool sol = false;

            for (int i=0,j=n-1 ; i<k ; i++,j--){
                  if (j<=i+1)break;
                  if (s[i] != s[j])break;
                  if (i==k-1){
                        sol = true;
                  }
            }
            if (k==0)sol = true;
            cout << (sol?"YES":"NO") << endl;
      }

      return 0;
}
