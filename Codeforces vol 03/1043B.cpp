#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll A[1005] , n;

int main()
{
      cin >> n;
      for (int i=0 ; i<n ; i++)cin >> A[i];

      for (int i=n ; i>=1 ; i--)A[i] = A[i]-A[i-1];

      vector < ll > ans;

      for (int i=1 ; i<=n ; i++){

            bool temp = true;
            for (int j = 0; j<n ; j++){
                  if (A[j]!=A[j%i])temp = false;
            }

            if (temp)ans.push_back(i);
      }

      cout << ans.size() << endl;
      for (int i=0 ; i<ans.size();i++)cout << ans[i] << " ";
      cout << endl;


      return 0;
}
