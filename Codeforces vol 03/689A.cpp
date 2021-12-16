#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s;
ll A[15];

bool up()
{
      if (A[1]==1 || A[2]==1 || A[3]==1)return true;
      return false;
}
bool down()
{
      if (A[9]==1  || A[7]==1)return true;
      return false;
}

bool lft()
{
      if (A[1]==1 || A[4]==1 || A[7]==1)return true;
      return false;
}
bool rgt()
{
      if (A[9]==1 || A[6]==1 || A[3]==1)return true;
      return false;
}

int main()
{
      while(true){
      memset(A,0,sizeof A);
      ll n;
      cin >> n;
      cin >> s;


      for (int i=0 ; i<s.size(); i++){

            ll temp = s[i] - '0';
            A[temp] = 1;
      }

      if (A[0]==1){
            if (A[1]==1 || A[2]==1 || A[3]==1)cout << "YES" << endl;
            else cout << "NO" << endl;
      }
      else if (up() && down() && lft() && rgt()){
            cout << "YES" << endl;
      }
      else cout << "NO" << endl;

      return 0;

      }

}
