#include<bits/stdc++.h>
#define iiu unsigned int
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

struct matrix
{
      iiu row,col,arr[55][55];

      matrix(iiu x, iiu y)
      {
            row = x;
            col = y;
            memset(arr,0,sizeof arr);
      }
};

void showMatrix(matrix A)
{
      cout << "row:"<< A.row << "  col:" << A.col << endl;
      for (int i=0 ; i<A.row ; i++){
            for (int j=0 ; j<A.col ; j++)cout << A.arr[i][j] << " ";
            cout << endl;
      }
}

matrix indentity(int a, int b)
{
      matrix ret(a,b);
      for (int i=0 ; i<min(a,b) ; i++)ret.arr[i][i] = 1;
      return ret;
}

matrix transition(ll k)
{
      matrix ret(k+2,k+2);
      ret.arr[k+1][k+1] = 1;
      for (int i=k ; i>0 ; i--){
            for (int j=0 ; j<k+2 ; j++){
                  if (j==k+1)ret.arr[i][j] = 1;
                  else ret.arr[i][j] = ret.arr[i+1][j]+ret.arr[i+1][j+1];
            }
      }
      ret.arr[0][0] = 1;
      for (int j=1 ; j<k+2 ; j++)ret.arr[0][j] = ret.arr[1][j];
      return ret;
}

matrix multiplication(matrix A, matrix B)
{
      matrix ret(A.row,B.col);
      for (int i=0 ; i<A.row ; i++){
            for (int j=0 ; j<B.col ; j++){
                  for (int l = 0 ; l<A.col ; l++){
                        ret.arr[i][j] += A.arr[i][l]*B.arr[l][j];
                  }
            }
      }
      return ret;
}

matrix bigmod(matrix A, ll pw)
{
      if (pw==0)return indentity(A.row,A.col);
      matrix temp = bigmod(A,pw/2);
      temp = multiplication(temp,temp);
      if (pw%2)temp = multiplication(temp,A);
      return temp;
}

int main()
{
      int tc;
      cin >> tc;

      for (int _t=1 ; _t<=tc; _t++){
            ll n,k;
            cin >> n >> k;
            matrix A = bigmod(transition(k),n-1);
            iiu ans = 0;
            for (int i=0 ; i<k+2 ; i++)ans+=A.arr[0][i];
            cout <<"Case "<<_t<<": "<< ans<<"\n";
      }


      return 0;
}
/*
1
3 2

1 1 1
0 1 1
0 0 1
*/
