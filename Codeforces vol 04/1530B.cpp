#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

ll A[30][30], B[30][30], ansA, ansB , n,m;
int dx[]={-1,0,1,0,-1,-1,1,1},dy[]={0,1,0,-1,-1,1,1,-1};

bool check(ll x, ll y)
{
      if (x>=1 && x<=n && y>=1 && y<=m)return true;
      return false;
}

bool edge(ll x, ll y)
{
      if (x==1 || x==n || y==1 || y==m)return true;
      return false;
}

ll ins(ll x, ll y)
{

}

ll funA()
{
      ll ret = 0;
      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                  if (edge(i,j) && A[i][j]==0){
                        A[i][j] = 1;
                        ret++;
//                        cout << "i,j " << i << j << endl;
                        for (int k = 0 ; k<8 ; k++){
                              ll x = i+dx[k], y = j+dy[k];
                              if (check(x,y)){
//                        cout << "x,y " << x << y << endl;
                                    A[x][y] = -1;
                              }
                        }
                  }
            }
      }
      return ret;
}

ll funB()
{
      ll ret = 0;
      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                  if (i==1 && j==1)continue;
                  if (edge(i,j) && B[i][j]==0){
                        B[i][j] = 1;
                        ret++;
                        for (int k = 0 ; k<8 ; k++){
                              ll x = i+dx[k], y = j+dy[k];
                              if (check(x,y)){
                                    B[x][y] = -1;
                              }
                        }
                  }
            }
      }
      return ret;
}

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            cin >> n >> m;
            memset(A,0,sizeof A);
            memset(B,0,sizeof B);
            ansA = ansB = 0;
            if (funA()>funB()){
                  for (int i=1 ; i<=n ; i++){
                        for (int j=1 ; j<=m ; j++){
                              if (A[i][j]==-1)A[i][j] = 0;
                              cout << A[i][j] ;
                        }
                        cout << endl;
                  }
            }
            else {
                  for (int i=1 ; i<=n ; i++){
                        for (int j=1 ; j<=m ; j++){
                              if (B[i][j]==-1)B[i][j] = 0;
                              cout << B[i][j] ;
                        }
                        cout << endl;
                  }
            }
            cout << endl;
      }

      return 0;
}
