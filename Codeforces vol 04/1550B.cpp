#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;


string s;
ll x , n,a,b;

ll Bmaximize()
{
      return n*b;
}
ll Bminimize()
{
      return ((x+2)/2)*b;
}

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            cin >> n >> a >> b;
            cin >> s;
            x = 1;
            for (int i=1 ; i<n ; i++){
                  if (s[i]!=s[i-1])x++;
            }

            ll sum = n*a;
            if (b>0)sum+=Bmaximize();
            else sum+=Bminimize();

            cout << sum << endl;
      }


      return 0;
}
/*
10
5 1 3
01010

5 -1 3
01010

5 1 -3
01010

5 -1 -3
01010

6 1 3
010101

6 -1 3
010101

6 1 -3
010101

6 -1 -3
010101
*/
