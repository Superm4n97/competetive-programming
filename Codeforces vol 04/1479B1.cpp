#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

int A[maxn] , nxt[maxn] , Log[maxn] , cnt = 0;

int main()
{
      int n;
      cin >> n;

      for (int i=1 ; i<=n ; i++) cin >> A[i];
      for (int i=0 ; i<=n+3 ; i++)Log[i]= n+3;

      for (int i=n ; i>=0 ; i--){
            nxt[i] = Log[A[i]];
            Log[A[i]] = i;
      }

      int x = 0 , y = 0;

      for (int i=1 ; i<=n ; i++){
            if (A[i] == A[x]){
                  x = i;
            }
            else if (A[i] == A[y]){
                  y = i;
            }
            else if (nxt[x]>nxt[y]){
                  x = i;
                  cnt++;
            }
            else {
                  y = i;
                  cnt++;
            }
      }
      cout << cnt << "\n";

      return 0;
}
