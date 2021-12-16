#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            int n;
            cin >> n;
            int A[n+5], nxt[n+5];
            nxt[0] = 0;
            for (int i = 1 ; i<=n; i++)cin >> A[i];
            nxt[1] = 1;
            for (int i=2 ; i<=n ; i++){
                  if (A[i]>A[nxt[i-1]])nxt[i] = i;
                  else nxt[i] = nxt[i-1];
            }

            int pre = nxt[n];
            vector<int> ans;
            while(pre>0){
                  for (int i=pre ; i<=n ; i++){
                        if (nxt[i]==pre){
                              ans.push_back(A[i]);
                        }
                        else break;
                  }
                  pre = nxt[pre-1];
            }
            for (int i=0 ; i<n ; i++)cout << ans[i] << " ";
            cout << "\n";
      }

      return 0;
}
