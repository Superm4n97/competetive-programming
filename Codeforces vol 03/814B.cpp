#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005

using namespace std;

ll A[maxn] , B[maxn] , cnt[maxn] , n;

int main()
{
      cin >> n;

      vector < ll > v;

      for (int i=1 ; i<=n ; i++)cin >> A[i];
      for (int i=1 ; i<=n ; i++)cin >> B[i];

      for (int i=1 ; i<=n; i++){
            if (A[i]==B[i])cnt[A[i]] = 1;
      }

      for (int i=1 ; i<=n ; i++){
            if (cnt[i]==0)v.push_back(i);
      }

      if (v.size()==1){
            for (int i=1 ; i<=n ; i++){
                  if (A[i]!=B[i])A[i] = v[0];
            }
      }
      else {
            vector < ll > id;
            for (int i=1 ; i<=n ; i++){
                  if (A[i]!=B[i])id.push_back(i);
            }

            //show(id.size());

            if (A[id[0]] != v[0] && A[id[1]] != v[1])A[id[0]] = v[1], A[id[1]] = v[0];
            else A[id[0]] = v[0], A[id[1]] = v[1];
      }

      for (int i=1 ; i<=n ; i++)cout << A[i] << " ";


      return 0;
}
