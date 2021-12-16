#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

ll A[205][206] , n;
string s[205];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

bool check(ll x, ll y)
{
      if (x>=0 && x<n && y>=0 && y<n)return true;
      return false;
}

void dfs(ll x, ll y, ll ch)
{
//      show(x);
//      show(y);

      A[x][y] = 1;
      for (int i=0 ; i<4 ; i++){
            ll a = x+dx[i] , b = y+dy[i];
            if (check(a,b))
            {
                  //show(a);show(b);

                  if(a==n-1 && b==n-1){
                        A[n-1][n-1] = 1;
                        return;
                  }
                  if (s[a][b]==ch && A[a][b]==0){
                        dfs(a,b,ch);
                  }
            }
      }
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){

            cin >> n;
            for (int i=0 ; i<n ; i++)cin >> s[i];

            ll temp  = 0;
            char ch;

            memset(A,0,sizeof A);
            dfs(0,0,'0');
            if (A[n-1][n-1]==1)temp++ , ch = '0';

            memset(A,0,sizeof A);
            dfs(0,0,'1');
            if (A[n-1][n-1]==1)temp++ , ch = '1';

            //show(temp);

            if (temp==0)cout << 0 << endl;
            else if (temp==1){
                  vector < pair <ll,ll> > vp;

                  if (ch==s[n-1][n-2])vp.push_back({n-1,n-2});
                  if (ch==s[n-2][n-1])vp.push_back({n-2,n-1});

                  cout << vp.size() <<endl;
                  for (int i=0 ; i<vp.size() ; i++)cout << vp[i].first+1 << " " << vp[i].second+1 << endl;
            }
            else {

                  vector < pair <ll,ll> > vp;

                  if ('0'==s[0][1])vp.push_back({0,1});
                  if ('0'==s[1][0])vp.push_back({1,0});
                  if ('1'==s[n-1][n-2])vp.push_back({n-1,n-2});
                  if ('1'==s[n-2][n-1])vp.push_back({n-2,n-1});

                  cout << vp.size() <<endl;
                  for (int i=0 ; i<vp.size() ; i++)cout << vp[i].first+1 << " " << vp[i].second+1 << endl;
            }
      }

      return 0;
}
