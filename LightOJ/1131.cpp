#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x<< endl
#define maxRow 7

using namespace std;

ll a[3],b[3],c[3],f[5],g[5], mod,n;

struct matrix
{
      ll row, col , arr[maxRow][maxRow];

      matrix(ll x, ll y){
            row = x;
            col = y;
            memset(arr,0,sizeof arr);
      }
};

ll amod(ll a)
{
      return a - a/mod*mod;
}

matrix indentityMatrix(ll x, ll y)
{
      matrix ret(x,y);
      for (int i=0 ; i<min(x,y) ; i++)ret.arr[i][i] = 1;
      return ret;
}

matrix matrixMultiplication(matrix A, matrix B)
{
      matrix ret(A.row,B.col);
      for (int i=0 ; i<A.row ; i++){
            for (int j=0 ; j<B.col ; j++){
                  ll temp = 0;
                  for (int k = 0 ; k<A.col ; k++){
                        temp = amod(temp+amod(A.arr[i][k]*B.arr[k][j]));
                  }
                  ret.arr[i][j] = temp;
            }
      }
      return ret;
}

void showMatrix(matrix A)
{
      cout << endl;
      for (int i=0 ; i<A.row ; i++){
            for (int j=0 ; j<A.col;j++)cout << A.arr[i][j] << " ";
            cout << endl;
      }
      cout << endl;
}

matrix matBigmod(matrix A, ll pw)
{
      if (pw==0)return indentityMatrix(A.row,A.col);
      matrix temp = matBigmod(A,pw/2);
      temp = matrixMultiplication(temp,temp);
      if (pw%2)temp = matrixMultiplication(temp,A);
      return temp;
}

matrix initializeTansitionMatrix()
{
      matrix ret(6,6);
      ret.arr[0][0] = a[1];
      ret.arr[0][1] = b[1];
      ret.arr[0][5] = c[1];
      ret.arr[1][0] = 1;
      ret.arr[2][1] = 1;

      ret.arr[3][2] = c[2];
      ret.arr[3][3] = a[2];
      ret.arr[3][4] = b[2];

      ret.arr[4][3] = 1;
      ret.arr[5][4] = 1;
      return ret;
}

matrix initializeBaseMatrix()
{
      matrix ret(6,1);
      ret.arr[0][0] = f[2];
      ret.arr[1][0] = f[1];
      ret.arr[2][0] = f[0];
      ret.arr[3][0] = g[2];
      ret.arr[4][0] = g[1];
      ret.arr[5][0] = g[0];
      return ret;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc; _t++){
            scanf("%lld %lld %lld",&a[1],&b[1],&c[1]);
            scanf("%lld %lld %lld",&a[2],&b[2],&c[2]);
            scanf("%lld %lld %lld",&f[0],&f[1],&f[2]);
            scanf("%lld %lld %lld",&g[0],&g[1],&g[2]);
            scanf("%lld",&mod);
            ll q;
            scanf("%lld",&q);
            printf("Case %d:\n",_t);

            while(q--){
                  scanf("%lld",&n);
                  if (n<3){
                        printf("%lld %lld\n",f[n]%mod , g[n]%mod);
                  }
                  else {
                        matrix transition = matBigmod(initializeTansitionMatrix(),n-2);
                        matrix base = matrixMultiplication(transition,initializeBaseMatrix());
                        printf("%lld %lld\n",base.arr[0][0],base.arr[3][0]);
                  }
            }
      }

      return 0;
}
/*
1
1 1 0
0 0 0
0 1 1
0 0 0
20000
1
3
*/
