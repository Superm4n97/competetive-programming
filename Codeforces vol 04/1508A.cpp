#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n;
string ans , s[4];

char countLowChar(int id)
{
      int cnt1 = 0;
      for (int i=0 ; i<2*n ; i++){
            if (s[id][i]=='1')cnt1++;
      }

      if (cnt1<=n)return '1';
      return '0';
}

int countChar(int id, char ch)
{
      int ret = 0;
      for (int i=0 ; i<2*n ; i++){
            if (s[id][i]==ch)ret++;
      }
      return ret;
}

void GenerateAns(int a, int b, char lw)
{
      ans = "";
      int x = 0, y = 0;
      while(x<2*n || y<2*n){
            if (x>=2*n){
                  ans.push_back(s[b][y]);
                  y++;
            }
            else if (y>=2*n){
                  ans.push_back(s[a][x]);
                  x++;
            }
            else {
                  if (s[a][x]==s[b][y]){
                        ans.push_back(s[a][x]);
                        x++;
                        y++;
                  }
                  else if (s[a][x]==lw){
                        ans.push_back(s[a][x]);
                        x++;
                  }
                  else {///need to debug
                        ans.push_back(s[b][y]);
                        y++;
                  }
            }
      }
      while(ans.size()<3*n){
            ans.push_back('0');
      }
      return;
}

bool solve(int a, int b, int c)
{
      char lw = countLowChar(a);

      int temp = countChar(b,lw);
      if (temp<=n){
            GenerateAns(a,b,lw);
            return true;
      }

      temp = countChar(c,lw);
      if (temp<=n){
            GenerateAns(a,c,lw);
            return true;
      }

      return false;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            cin >> s[0] >> s[1] >> s[2];

            if (solve(0,1,2)){
                  cout << ans << endl;
            }
            else if (solve(1,0,2)){
                  cout << ans << endl;
            }
            else if (solve(2,1,0)){
                  cout << ans <<endl;
            }
      }

      return 0;
}
