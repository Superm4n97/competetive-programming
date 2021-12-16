#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn  2005

using namespace std;

int main()
{
      ll n;
      cin >> n;
      ll A[maxn];

      for (int i=1 ; i<=n ; i++)cin >> A[i];

      ll pre = 0;

      cout << n+1 << endl;

      for (int i=n ; i>=1 ; i--){
            A[i]+=pre;
            ll temp = A[i] - i;

            if (temp<=0){
                  temp*=-1;
                  cout << 1 << " " << i << " " << temp << endl;
                  pre+=temp;
            }
            else {
                  ll tut = (n+1) - temp%(n+1);
                  cout << 1 << " " << i << " " << tut << endl;
                  pre+=tut;
            }
      }
      cout << 2 << " " << n << " " << n+1 << endl;


      return 0;
}
