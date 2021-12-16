#include<bits/stdc++.h>
#define ll unsigned int
#define show(x) cout << #x << " : " << x << endl
#define maxRow 55

using namespace std;

string s , ch;
ll sSize, chSize,n;

struct matrix
{
      /**maxRow is the max size of transition
      matrices**/
      ll row, col , arr[maxRow][maxRow];
      matrix(ll x, ll y){
            row = x;
            col = y;
            memset(arr,0,sizeof arr);
      }
};
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
                        temp = temp+A.arr[i][k]*B.arr[k][j];
                  }
                  ret.arr[i][j] = temp;
            }
      }
      return ret;
}
matrix matBigmod(matrix A, ll pw)
{
      if (pw==0)return indentityMatrix(A.row,A.col);
      matrix temp = matBigmod(A,pw/2);
      temp = matrixMultiplication(temp,temp);
      if (pw%2)temp = matrixMultiplication(temp,A);
      return temp;
}

bool match(string st, ll lst, ll cnt)
{
      int id = lst-cnt+1;
      for (int i=0 ; i<cnt ; i++, id++){
            if (s[i] != st[id])return false;
      }
      return true;
}

matrix initializeTansitionMatrix()
{
      ///this should be powered up
      matrix ret(sSize,sSize);//size of transpose mat
      string st = s;
      for (int i=0 ; i<sSize ; i++){
            for (int j=0 ; j<chSize ; j++){
                  int retX = 0;
                  st[i] = ch[j];

                  for (int k=1 ; k<=i+1 ; k++){
                        if (match(st,i,k))retX = k;
                  }
                  ret.arr[i][retX]++;
            }
            st[i] = s[i];
      }

//      for (int i=0 ; i<sSize ; i++){
//            for (int j=0 ; j<sSize ; j++){
//                  cout << ret.arr[i][j] << " ";
//            }
//            cout << endl;
//      }

      return ret;
}

int main()
{
      initializeTansitionMatrix();
      int tc;
      cin >> tc;
      for (int _t = 1 ; _t<=tc ; _t++){
            cin >> n;
            cin >> ch >> s;
            chSize = ch.size();
            sSize = s.size();
            matrix mt = initializeTansitionMatrix();
            matrix ans = matBigmod(mt,n);
            ll cnt = 0;
            //for (int i=0 ; i<ans.row ; i++){
                  for (int j=0 ; j<ans.col ; j++){
                        cnt+=ans.arr[0][j];
                  }
            //}
            cout << "Case "<<_t<<": "<< cnt << "\n";
      }

      return 0;
}
/*
1
4
acd
ca

1
5
ab
aaa

1
1
ab
aaa
*/
