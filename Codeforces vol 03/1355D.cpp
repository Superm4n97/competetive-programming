#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll A[maxn] , mark[maxn];

int main()
{
      ll n,s;
      cin >> n >> s;

      ll t = s;

      for (int i=1 ; i<n; i++){

            A[i] = 1;
            t--;
      }

      A[n] = t;
      ll tempSum = 0;

      for (int i=1 ; i<n ; i++){

            tempSum+=A[i];
            mark[tempSum] = 1;
            mark[s - tempSum] = 1;
      }

      ll k = -1;

      for (int i=1 ; i<s ; i++){

            if (mark[i]==0){
                  k = i;
                  break;
            }
      }
      if (k==-1)cout << "NO" << endl;
      else {
            cout << "YES" << endl;
            for (int i=1 ; i<=n ;i++)cout << A[i] << " ";
            cout << endl;
            cout << k << endl;
      }


      return 0;
}
