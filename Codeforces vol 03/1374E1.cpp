#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n,m;
      cin >> n >> m;
      vector < ll > both , A,B;

      for (int i=0 ; i<n; i++){

            ll t,a,b;
            cin >> t >> a >> b;
            if (a==1 && b==1)both.push_back(t);
            if (a==1 && b==0)A.push_back(t);
            if (a==0 && b==1)B.push_back(t);
      }

      sort(A.begin(),A.end());
      sort(B.begin(),B.end());

      for (int i=0 ; i<min(A.size(),B.size()) ; i++)both.push_back(A[i]+B[i]);

      ll ans = -1;

      if (both.size()>=m){

            sort(both.begin(),both.end());
            ans = 0;
            for (int i=0 ; i<m;i++)ans+=both[i];
      }

      cout << ans << endl;

      return 0;
}
