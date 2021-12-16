/**Catalan For non prime mod in O(n^2)**/
#include<bits/stdc++.h>
#define ll long long int
#define maxn 1005
#define mod 1000000

using namespace std;

ll CAT[maxn];

ll amodb(ll a, ll b)
{
      return a - a/b*b;
}

ll catalan(ll n)
{
      ll ret = 0;
      for (int i=0; i<n ; i++){
            ret += amodb(CAT[i]*CAT[n-1-i],mod);
            ret = amodb(ret,mod);
      }
      return ret;
}

int main()
{
      CAT[0] = CAT[1] = 1;
      for (int i=2 ; i<maxn ; i++)CAT[i] = catalan(i);

      while(true){
            ll n;
            cin >> n;
            if (n==0)break;
            cout << CAT[n] << endl;
      }

      return 0;
}
