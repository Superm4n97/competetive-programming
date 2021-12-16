#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector <ll> A,B;
ll n ,d , m, na,nb, ans = 0;

int main()
{
      cin >> n >> d >> m;
      for (int i=0 ; i<n ; i++){

            ll a;
            cin >> a;

            if (a>m)A.push_back(a);
            else {
                  B.push_back(a);
                  ans+=a;
            }
      }

      na = A.size() , nb = B.size();

      if (!A.empty())sort(A.rbegin(),A.rend());
      if (!B.empty())sort(B.rbegin(),B.rend());

      for (int i=1 ;i<nb ; i++)B[i]+=B[i-1];
      for (int i=1 ;i<na ; i++)A[i]+=A[i-1];


      for (int i=0 ; i<na ; i++){

            ll need = i*d, have = nb+(na-i-1);
            if (have<need)break;

            ll sum = 0;
            sum+=A[i];

            ll mn = max(need - (na-i-1) , 0LL);


            ll id = nb-mn-1;


            if (id>=0)sum+=B[id];


            ans = max(ans,sum);

      }

      cout << ans << endl;

      return 0;
}

/**
0 1 2 3  - 4
0 1 2 3 4 5  - 6

**/
