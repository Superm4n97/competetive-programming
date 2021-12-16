#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define mod 1000000007

using namespace std;

struct matrix
{
      ll arr[10][10];
      matrix()
      {
            memset(arr,0,sizeof arr);
      }

};
matrix transition[maxn];

ll amod(ll a)
{
      return a - a/mod*mod;
}

matrix multiplication1(matrix A, matrix B)
{
      ///A te base
      matrix ret;
      for (int i=0 ; i<10 ; i++){
            for (int j=0 ; j<10 ; j++){
                  if (A.arr[i][j]==1){
                        for (int k=0 ; k<10 ; k++){
                              ret.arr[i][k] = amod(ret.arr[i][k]+B.arr[j][k]);
                        }
                  }
            }
      }
      return ret;
}
matrix multiplication2(matrix A, matrix B)
{
      ///B = 10*1
      matrix ret;
      for (int i=0; i<10 ; i++){
            for (int j=0 ; j<10; j++){
                  ret.arr[i][0] = amod(ret.arr[i][0]+amod(A.arr[i][j]*B.arr[j][0]));
            }
      }
      return ret;
}
matrix base()
{
      matrix ret;
      ret.arr[0][9] = 1;
      ret.arr[1][9] = 1;
      ret.arr[1][0] = 1;
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

void initialation()
{
      transition[1] = base();
      for (int i=2 ; i<maxn ; i++){
            transition[i] = multiplication1(transition[1],transition[i-1]);
      }
}

int main()
{
      initialation();

      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n,m,ans = 0;
            scanf("%lld %lld",&n,&m);
            matrix B;
            while(n){
                  B.arr[n%10][0]++;
                  n/=10;
            }
            matrix res = multiplication2(transition[m],B);
            for (int i=0 ; i<10 ; i++)ans = amod(ans+res.arr[i][0]);
            printf("%lld\n",ans);
      }

      return 0;
}
