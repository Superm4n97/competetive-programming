#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,m,k,l;
      cin >> n >> m >> k >> l;

      ll temp = (l+k+m-1)/m;
      temp*=m;

      if (temp<=n)cout << temp/m << endl;
      else cout << -1 << endl;


}

/**

gift-k >= l
gift >= l+k

temp*m >= l+k

 temp = ((l+k)+m-1)/m;
 temp*m

**/
