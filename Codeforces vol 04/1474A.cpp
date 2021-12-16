#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            scl(n);
            string s;
            cin >> s;

            ll pre = 0;

            for (int i=0 ; i<n ; i++){
                  if (pre==0){
                        printf("1");
                        if (s[i]=='1')pre = 2;
                        else pre = 1;
                  }
                  else if (pre==1){
                        if (s[i]=='0'){
                              printf("0");
                              pre = 0;
                        }
                        else {
                              printf("1");
                              pre = 2;
                        }
                  }
                  else {
                        if (s[i]=='0'){
                              printf("1");
                              pre = 1;
                        }
                        else {
                              printf("0");
                              pre = 1;
                        }
                  }
            }
            printf("\n");
      }


}
