#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            ll A[n+5];
            for (int i=1 ; i<=n ; i++)cin >> A[i];

            ll L = 1 , R = n , sol = 1;

            for (int i=n ; i>=1 ; i--){
                  if (A[L] == i)L++;
                  else if (A[R] == i)R--;
                  else {
                        sol = 0;
                        break;
                  }
            }
            if (!sol){
                  cout << -1 << endl;
                  continue;
            }

            vector<pair<ll,ll> > ans;

            ll ptL = -1 , ptR = 1;
            L = 1 , R = n;
            while(L<=R){
                  if (A[L]>=A[R]){
                        ans.push_back({ptL,A[L]});
                        L++;
                        ptL--;
                  }
                  else {
                        ans.push_back({ptR,A[R]});
                        R--;
                        ptR++;
                  }
            }
            sort(ans.begin(),ans.end());

            for (int i=0 ; i<n ; i++)cout << ans[i].second << " ";
            cout << endl;
      }

      return 0;
}
