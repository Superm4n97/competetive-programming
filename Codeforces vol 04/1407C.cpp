#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll A[n+5];

      queue < ll > q;

      for (int i = 1 ; i<=n ; i++)q.push(i);

      while (q.size()>1) {

            ll id1 = q.front();
            q.pop();
            ll id2 = q.front();
            q.pop();

            ll res1 , res2;

            printf("? %I64d %I64d\n", id1 , id2);
            fflush(stdout);
            scanf("%I64d",&res1);/**/

            printf("? %I64d %I64d\n", id2 , id1);
            fflush(stdout);
            scanf("%I64d",&res2);/**/

            if (res1>res2){
                  A[id1] = res1;
                  q.push(id2);
            }
            else{
                  A[id2] = res2;
                  q.push(id1);
            }
      }

      A[q.front()] = n;

      cout << "! ";
      for (int i=1 ; i<=n ; i++)cout << A[i] << " ";
      cout << endl;

      return 0;
}
