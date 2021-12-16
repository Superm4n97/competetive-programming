#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%I64d",&tc);

      while(tc--){

            ll n , m;
            scanf("%I64d",&n);

            vector < ll > fac;

            m = n;

            for (ll i = 2 ; i*i<=m ; i++){
                  if (m%i==0){

                        fac.push_back(i);

                        while(m%i==0)m/=i;
                  }
            }
            if (m>1)fac.push_back(m);


            if (fac.size()==2 && fac[0]*fac[1]==n){
                  printf("%I64d %I64d %I64d\n1\n",fac[0],fac[1],n);
            }
            else {

                  ll sz = fac.size();
                  ll cycle[2*sz+4];

                  vector < ll > div;
                  map < ll,ll > mp;

                  for (ll i = 2 ; i*i<=n ; i++){
                        if (n%i==0){
                              div.push_back(i);
                              if (i!=n/i)div.push_back(n/i);
                        }
                  }
                  div.push_back(n);

                  for (int i=1 ; i<=sz*2 ; i++){
                        if (i%2==1){
                              cycle[i] = fac[i/2];
                        }
                        else{
                              if (i==2*sz){
                                    cycle[i] = n;
                              }
                              else {
                                    cycle[i] = fac[i/2]*fac[(i-1)/2];
                              }
                        }

                        mp[cycle[i]] = 1;
                  }

                  for (ll i=1 ; i<=2*sz ; i+=2){

                        printf("%I64d ",cycle[i]);

                        for (ll j = 1 ; j<div.size() ; j++){
                              if (mp[div[j]]==0 && div[j]%cycle[i]==0){
                                    printf("%I64d ",div[j]);
                                    mp[div[j]] = 1;
                              }
                        }

                        printf("%I64d ",cycle[i+1]);
                  }
                  printf("\n");
                  printf("0\n");
            }

      }


      return 0;
}

/**
0 1 2 3
1 2 3 4 5 6 7 8
**/
