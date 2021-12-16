#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n,k , A[maxn] , B[maxn] , idA[maxn] , idB[maxn];

int main()
{
      cin >> n >> k;

      for (int i=1 ; i<=n ; i++){
            cin >> A[i];
            idA[A[i]] = i;
      }

      for (int i=1 ; i<=n ; i++){
            cin >> B[i];
            idB[B[i]] = i;
      }

      ll x = 0 , y = 0;
      queue < ll > q;

      for (int i=1 ; i<=n ; i++){
            x = max(x,idB[A[i]]);
            y = max(y,idA[B[i]]);

            if (x==y && x==i){
                  q.push(A[i]);
            }
      }

      if (q.size()<k){
            cout << "NO" << endl;
      }
      else {
            cout << "YES" << endl;
            char ch = 'a';
            string s;

            for (int i=0 ; i<=n+2 ; i++)s.push_back('a');

            for (int i=1 ; i<=n ; i++){
                  //cout << ch;
                  s[A[i]] = ch;
                  if (!q.empty()){
                        if (q.front()==A[i]){
                              q.pop();
                              ch++;
                              if (ch>'z')ch = 'z';
                        }
                  }
            }

            for (int i=1; i<=n ; i++)cout << s[i];
            cout << endl;
      }

      return 0;
}
