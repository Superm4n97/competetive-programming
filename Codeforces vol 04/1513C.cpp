#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x<< endl
#define maxRow 15
#define mod 1000000007

using namespace std;

struct matrix
{
      ll row, col , arr[maxRow][maxRow];

      matrix(ll x, ll y){
            row = x;
            col = y;
            memset(arr,0,sizeof arr);
      }
      matrix(){
            row = 10;
            col = 10;
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
      for (ll i=0 ; i<x ; i++)ret.arr[i][i] = 1;
      return ret;
}

matrix matrixMultiplication(matrix A, matrix B)
{
      matrix ret(A.row,B.col);
      for (ll i=0 ; i<A.row ; i++){
            for (ll j=0 ; j<B.col ; j++){
                  ll temp = 0;
                  for (ll k = 0 ; k<A.col ; k++){
                        temp = amod(temp+amod(A.arr[i][k]*B.arr[k][j]));
                  }
                  ret.arr[i][j] = temp;
            }
      }
      return ret;
}

matrix matrixAddition(matrix A, matrix B)
{
      matrix ret(10,10);
      for (int i=0 ; i<10 ; i++){
            for (int j=0; j<10 ; j++){
                  ret.arr[i][j] = amod(A.arr[i][j]+B.arr[i][j]);
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
      matrix ret(10,10);
      ret.arr[0][9] = 1;
      ret.arr[1][0] = 1;
      ret.arr[1][9] = 1;
      ret.arr[2][1] = 1;
      ret.arr[3][2] = 1;
      ret.arr[4][3] = 1;
      ret.arr[5][4] = 1;
      ret.arr[6][5] = 1;
      ret.arr[7][6] = 1;
      ret.arr[8][7] = 1;
      ret.arr[9][8] = 1;
      return ret;
}

int main()
{
      matrix POW[25];
      ll PW[25];
//      POW[0] = indentityMatrix(10,10);
      POW[0] = initializeTansitionMatrix();
      for (int i=1 ; i<25 ; i++)POW[i] = matrixMultiplication(POW[i-1],POW[0]);
      PW[0] = 1;
      for (int i=1 ; i<25 ; i++)PW[i] = PW[i-1]*2;

      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc; _t++){
            ll n,m;
            scanf("%lld %lld",&n,&m);
            matrix A(10,1);
            while(n){
                  ll temp = n - n/10*10;
                  n/=10;
                  A.arr[temp][0]++;
            }

            ll ans = 0;

//            matrix T = matBigmod(initializeTansitionMatrix(),m);
            matrix res(10,10);
            for (int i=24; i>=0 ; i--){
                  if (PW[i]<=m){
                        m-=PW[i];
                        res = matrixAddition(res,POW[i]);
                  }
            }
//            showMatrix(res);

            res = matrixMultiplication(res,A);

            for (int i=0 ; i<10 ; i++)ans = amod(ans+res.arr[i][0]);
            printf("%lld\n",ans);
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
