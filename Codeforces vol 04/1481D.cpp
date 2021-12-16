#include<bits/stdc++.h>

using namespace std;

void printDuo(int a, int b, int k)
{
      for (int i=0 ; i<=k ; i++){
            if (i&1)cout << b << " ";
            else cout << a << " ";
      }
}

void solve(int b, int k)
{
      int a = 1, c = 3;
      if (b==1)a = 2;
      if (b==3)c = 2;

      cout << "YES\n";
      if (k%4==0){
            printDuo(b,a,k/2);
            printDuo(c,b,k/2-1);
      }
      else {
            printDuo(a,b,k/2);
            printDuo(c,b,k/2-1);
      }
      cout << "\n";
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            int n,k;
            cin >> n >> k;
            string S[n+5];
            for (int i=0 ; i<n ; i++)cin >> S[i];

            if (k&1){
      cout << "YES\n";
                  printDuo(1,2,k);
      cout << "\n";                  continue;
            }

            int a = 0,b = 0;
            for (int i=0 ; i<n; i++){
                  for (int j=i+1 ; j<n ; j++){
                        if (S[i][j]==S[j][i])a = i+1, b = j+1;
                  }
            }

            if (a!=0){
      cout << "YES\n";
                  printDuo(a,b,k);
      cout << "\n";                  continue;
            }

            if (n==2){
                  cout << "NO\n";
                  continue;
            }

            if (S[0][1]==S[1][2] && S[1][2]==S[2][0]){
                  cout << "YES\n";
                  for (int i=0 ; i<=k ; i++){
                        if (i%3==0)cout << "1 ";
                        else if (i%3==1)cout << "2 ";
                        else cout << "3 ";
                  }
                  cout << "\n";
                  continue;
            }

            int middle = 0;
            if (S[2][0]==S[0][1])middle = 1;
            if (S[0][1]==S[1][2])middle = 2;
            if (S[1][2]==S[2][0])middle = 3;

            solve(middle,k);
      }

      return 0;
}
/*
2
3 4
*aa
b*a
bb*
3 6
*aa
b*a
bb*
*/
