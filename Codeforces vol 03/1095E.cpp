#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

string s;
ll n, mark[maxn] , L[maxn] , R[maxn] , cnt = 0;

int main()
{
      cin >> n;
      cin >> s;

      s = "*"+s;

      ll lft = n+1 , rgt = 0, temp= 0;

      for (int i =1 ; i<= n; i++){
            if(s[i]=='(')temp++;
            else temp--;

            if(temp == -1){

                  lft = i+1;
                  break;
            }
      }

      temp = 0;

      for (int i = n ; i>=1 ; i--){
            if (s[i]=='(')temp++;
            else temp--;

            if (temp==1){
                  rgt = i-1;
                  break;
            }
      }

      if (lft<=rgt){
            for (int i=lft ; i<=rgt ; i++)mark[i] = 1;
      }

      for (int i=1 ; i<=n ; i++){
            if (s[i]=='(')L[i] = 1;
            else L[i] = -1;

            L[i]+=L[i-1];
      }

      for (int i=n ; i>=1 ; i--){
            if (s[i]=='(')R[i] = 1;
            else R[i] = -1;

            R[i]+=R[i+1];
      }

      for (int i=1 ; i<=n ; i++){
            if (lft>i && rgt<i){
                  //show(i);
                  //show(s[i]);

                  if (s[i]=='('){
                        if (L[i-1] == R[i+1]*-1 + 1 && R[i+1]<=0){
                              cnt++;
                              //show(i);
                        }
                              //show(L[i-1]);
                              //show(R[i+1]);
                  }
                  else {
                        if (L[i-1]+1 == R[i+1]*-1 && R[i+1]<=0){
                              cnt++;
                              //show(i);
                        }
                              //show(L[i-1]);
                              //show(R[i+1]);
                  }
            }
      }

      cout << cnt << endl;



      return 0;
}
