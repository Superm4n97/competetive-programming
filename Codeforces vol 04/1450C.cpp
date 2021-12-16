#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n;
string s[305];

ll fn(ll k)
{
      for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                  ll cnt = 0 , x = 0 , y = 0;
                  if (j+2<n && s[i][j]=='X' && s[i][j+1]=='X' && s[i][j+2]=='X')cnt++;
                  if (j-2>=0 && s[i][j]=='X' && s[i][j-1]=='X' && s[i][j-2]=='X')cnt++;
                  if (i+2<n && s[i][j]=='X' && s[i+1][j]=='X' && s[i+2][j]=='X')cnt++;
                  if (i-2>=0 && s[i][j]=='X' && s[i-1][j]=='X' && s[i-2][j]=='X')cnt++;

                  if (i>0 && i+1<n && s[i][j]=='X' && s[i-1][j]=='X' && s[i+1][j]=='X')x++;
                  if (j>0 && j+1<n && s[i][j]=='X' && s[i][j-1]=='X' && s[i][j+1]=='X')y++;

                  if (x==1 && y==1)cnt = 4;
                  if (cnt==k){
                        s[i][j] = 'O';
//                        show(i);
//                        show(j);
//                        show(k);
//                        for (int p = 0 ; p<n ; p++)cout << s[p] << endl;
//                        cout << endl;
                  }
            }
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            cin >> n;
            for (int i=0 ; i<n ; i++)cin >> s[i];

            for (int i=4 ; i>=1 ; i--)fn(i);

            for (int i=0 ; i<n ; i++)cout << s[i] << "\n";
      }

      return 0;
}
