#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll k , sum = 0;;
            scanf("%I64d",&k);
            if (k%2){
                  printf("-1\n");
                  continue;
            }
            vector <ll> v;
            ll x = 2;
            while(sum<k){
                  if (x+sum<=k){
                        if (x==2)v.push_back(1LL);
                        else v.push_back(0LL);
                        sum+=x;
                        x*=2;
                  }
                  else x = 2;
            }
            cout << v.size() <<"\n";
            for (int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
            cout << endl;
      }

      return 0;
}

