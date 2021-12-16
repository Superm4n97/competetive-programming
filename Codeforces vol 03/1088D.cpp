#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll i = 31,  id = 0 , fix = 0 ,a=0,b=0 ;

      while (i--) {
            printf("? %I64d %I64d\n",id,id);
            fflush(stdout);

            ll response;
            scanf("%I64d",&response);

           // show(response);

            if (response==0){
                  break;
            }
            else {
                  if (id==0){
                        fix = response;
                        id = 1;
                        continue;
                  }
                  else {
                        if(response!=fix){
                              if (response==-1)a|=id;
                              else b|=id;
                        }
                  }
            }
            id*=2;
      }

          printf("! %I64d %I64d\n",a,b);
          fflush(stdout);


      return 0;
}
