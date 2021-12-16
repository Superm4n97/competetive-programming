#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

set < ll > st;

int main()
{
      ll b;
      cin >> b;

      for (ll i=1 ; i*i<=b ; i++){
            if (b%i==0){

                  st.insert(i);
                  st.insert(b/i);
            }
      }

      cout << st.size() << endl;


}

/**
[a,b] / a

6,8 = 24

b = 6
6 3 2 3 6 1 1 3

**/
