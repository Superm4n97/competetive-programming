#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

int n,A[maxn],st[maxn][22],q;
vector<int> G[maxn];

void clean()
{
      memset(st,-1,sizeof st);
      A[0] = 1;
}

int main()
{
      int tc;
      cin >> tc;

      for (int _t = 1 ; _t<=tc ; _t++){
            cin >> n >> q;
            clean();

            for (int i=1 ; i<n ; i++){
                  int u;
                  cin >> u >> A[i];
                  st[i][0] = u;
            }

            for (int j=1 ; j<22 ; j++){
                  for (int i=1; i<n ; i++){
                        int v = st[i][j-1];
                        if (v!=-1)st[i][j] = st[v][j-1];
                  }
            }

            cout << "Case "<<_t<<":\n";
            while(q--){
                  int x,k;
                  cin >> x >> k;

                  for (int j=20 ; j>=0 ; j--){
                        if (st[x][j] != -1 && A[st[x][j]]>=k)x = st[x][j];
                  }
                  cout << x << "\n";
            }
      }

      return 0;
}
