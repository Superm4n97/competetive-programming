#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x " : " << x << endl
#define maxn 200005

using namespace std;

int n,m,L[maxn],R[maxn] , ans = 0;
string s,t;

int main()
{
      memset(L,-1,sizeof L);
      cin >> n >>m;
      cin >> s >> t;

      int x = 0;

      for (int i=0;i<n ; i++){
            if (s[i]==t[x]){
                  L[x] = i;
                  x++;
            }
            if (x==m)break;
      }
      x = m-1;
      for (int i=n-1 ; i>=0 ; i--){
            if (x==0)break;
            if (s[i] == t[x]){
                  if (L[x-1]==-1 || L[x-1]>i){
                        x--;
                        continue;
                  }
                  ans = max(ans,i-L[x-1]);
                  x--;
            }
      }
      cout << ans << "\n";


      return 0;
}

