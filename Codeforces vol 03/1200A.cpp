#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "<< x << endl

using namespace std;

ll n,A[15];
string s;

void lft()
{
      for (int i=0 ; i<=9 ; i++){
            if (A[i]==0){
                  A[i] = 1;
                  return;
            }
      }
}

void rht()
{
      for (int i=9 ; i>=0 ; i--){
            if (A[i]==0){
                  A[i] = 1;
                  return;
            }
      }
}

int main()
{
      cin >>n ;
      cin >> s;

      for (int i=0 ; i<s.size() ; i++){
            if (s[i]=='L')lft();
            else if (s[i]=='R')rht();
            else {
                  ll temp = s[i] - '0';
                  A[temp] = 0;
            }
      }

      for (int i=0  ;i<=9 ;i++)cout << A[i];
      cout << endl;

      return 0;
}
