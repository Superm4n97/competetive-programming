#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

struct matrix
{
      ll row, col , arr[35][35];
      matrix(ll x , ll y)
      {
            row = x;
            col = y;
            memset(arr,0,sizeof arr);
      }
};

ll amod(ll a)
{
      return a%10;
}

matrix indentity(ll a)
{
      matrix ret(a,a);
      for (int i=0 ; i<a ; i++)ret.arr[i][i] = 1;
      return ret;
}

matrix multiplication(matrix A, matrix B)
{
      matrix ret(A.row,B.col);
      for (int i=0 ; i<A.row ; i++){
            for (int j=0 ; j<B.col ; j++){
                  for (int k=0 ; k<A.col ; k++){
                        ret.arr[i][j] = amod(ret.arr[i][j]+A.arr[i][k]*B.arr[k][j]);
                  }
            }
      }
      return ret;
}

matrix summation(matrix A, matrix B)
{
      matrix ret(A.row,A.col);
      for (int i=0 ; i<A.row ; i++){
            for (int j=0 ; j<A.col ; j++){
                  ret.arr[i][j] = amod(A.arr[i][j]+B.arr[i][j]);
            }
      }
      return ret;
}

matrix power(matrix A, ll p)
{
      if (p==0)return indentity(A.row);
      matrix temp = power(A,p/2);
      temp = multiplication(temp,temp);

      if (p%2)temp = multiplication(temp,A);
      return temp;
}

matrix bigmod(matrix A, ll p)
{
      if (p==1)return A;
      matrix temp = bigmod(A,p/2);
      temp = summation(temp,multiplication(power(A,p/2),temp));

      if (p%2)temp = summation(temp,power(A,p));
      return temp;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc; _t++){
            ll n,k;
            scanf("%lld %lld",&n,&k);
            matrix A(n,n);
            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<n ; j++){
                        scanf("%lld",&A.arr[i][j]);
                  }
            }
            matrix res = bigmod(A,k);
            printf("Case %d:\n",_t);
            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<n ; j++)printf("%lld",res.arr[i][j]);
                  printf("\n");
            }

      }

      return 0;
}
