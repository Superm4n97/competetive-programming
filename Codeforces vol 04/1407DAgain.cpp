#include<bits/stdc++.h>
#define ll long long int
#define maxn 300005

using namespace std;

ll n,A[maxn] , C[maxn] , B[maxn] , ans[maxn];

ll findChoto(ll id, ll val)
{
      while(true){
            if (C[id]==-1)return id;
            if (A[id]<=val)return id;

            id = C[id];
      }
}
ll findBoro(ll id, ll val)
{
      while(true){
            if (B[id]==-1)return id;
            if (A[id]>=val)return id;

            id = B[id];
      }
}

int main()
{
      cin >> n;

      for (int i=1 ; i<=n ; i++)cin >> A[i];

      C[1] = B[1] = -1;


      for (int i=2 ; i<=n ; i++){

            ans[i] = ans[i-1] + 1;

            if (A[i-1]<A[i]){

                  ll x = findBoro(i-1,A[i]);
                  ans[i] = min(ans[i],ans[x]+1);

                  if (A[x]>A[i] && ans[x]<ans[i])B[i] = x;
                  else B[i] = -1;
                  C[i] = i-1;

            }
      /**  1 2 3 4 5 6 7 8 9 0 1**/

      /**C - 1 1 3 1 5 -**/
      /**  1 3 3 5 2 4 1 2 2 2 5**/
      /**B - - - - 4 - 6**/
      /**a 0 1 2 3 1 2 1**/
            else if (A[i-1]>A[i]){
//            else{
                  ll x = findChoto(i-1,A[i]);
                  ans[i] = min(ans[i],ans[x]+1);

                  if (A[x]<A[i] && ans[x]<ans[i])C[i] = x;
                  else C[i] = -1;

                  B[i] = i-1;
            }
            else{
                  ll x = findChoto(i-1,A[i]) , y = findBoro(i-1,A[i]);

                  if (A[x]<A[i] && ans[x]<ans[i])C[i] = x;
                  else C[i] = -1;

                  if (A[y]>A[i] && ans[y]<ans[i])B[i] = y;
                  else B[i] = -1;
            }
      }



      for (int i=1 ; i<=n ; i++)cout << C[i] << " ";
      cout << endl;

      for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
      cout << endl;

      for (int i=1 ; i<=n ; i++)cout << B[i] << " ";
      cout << endl;

      for (int i=1 ; i<=n ; i++)cout << ans[i] << " ";
      cout << endl;

      cout << ans[n] << endl;


      return 0;
}

/**
1 2 3 4 5 6 7 8 9

9
1 2 3 1 4 1 2 3 6
3

11
1 2 2 3 3 4 1 1 2 3 6
5

10
4 1 1 1 4 5 5 5 5 4
2

11
1 3 3 5 2 4 1 2 2 2 5
3

**/
