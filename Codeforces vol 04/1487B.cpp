#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n,k;
            scanf("%I64d %I64d",&n,&k);

            if (n%2==0){
                  ll temp = k - k/n*n;
                  if (temp==0)temp = n;
                  printf("%I64d\n",temp);
            }
            else {
                  ll mid = (n+1)/2;
                  ll pre = 0;
                  while(true){
                        if(k/mid>pre){
                              ll temp = k/mid;
                              k += (k/mid - pre);
                              pre = temp;
                        }
                        else break;
                  }
                  k%=n;
                  if (k==0)k=n;
                  cout << k << endl;
            }
      }


      return 0;
}
