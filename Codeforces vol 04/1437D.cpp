#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(w) scanf("%I64d",&w)
#define maxn 200005

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5];
            for (int i = 1 ; i<=n ; i++)cin >> A[i];

            ll D[n+5];
            memset(D,0,sizeof D);

            queue<ll> q;
            q.push(1);
            q.push(A[2]);
            D[A[2]] = 1;

            for (int i=3 ; i<=n ; i++){

                  if (A[i]>A[i-1]){

                        D[A[i]] = D[q.front()]+1;
                        q.push(A[i]);
                  }
                  else {
                        q.pop();
                        D[A[i]] = D[q.front()]+1;
                        q.push(A[i]);
                  }
            }

            cout << D[A[n]] << endl;

      }

      return 0;
}
