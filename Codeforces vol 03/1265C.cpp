#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5];

            A[0] = 0;

            for (int i=1 ; i<=n ; i++)cin >> A[i];

            ll b = 1 , e = n , ans_g = 0 , ans_s = 0 , ans_b = 0;

            while(b<=e){

                  ll gd = (b+e)/2 , sl , br;
                  ll mid = gd;

                  while(A[gd]==A[gd+1])gd++;
                  sl = gd+1 , br = gd+1;

                  if (gd+sl+br>n/2){
                        e = mid-1;
                        continue;
                  }

                  while(A[gd+sl]==A[gd+sl+1])sl++;

                  if (gd+sl+br>n/2){
                        e = mid-1;
                        continue;
                  }


                  while(A[gd+sl+br]==A[gd+sl+br+1])br++;
                  ll mx_br = br;



                  while(A[gd+sl+br]==A[gd+sl+br+1] || gd+sl+br<n/2){
                        br++;

                        if (gd+sl+br>n/2)break;


                        if (A[gd+sl+br]!=A[gd+sl+br+1]){


                        //if (gd==2){show(br);}
                              mx_br = br;
                        }


                  }

                  br = mx_br;

                  /*
                  if (gd==2){
                        cout << endl;
                        show(sl);
                        show(br);
                  }
                  */

                  if (gd+sl+br>n/2){
                        e = mid-1;
                        continue;
                  }
                  else {
                        b = mid+1;
                        if (ans_g+ans_b+ans_s<gd+sl+br){
                              ans_g = gd;
                              ans_s = sl;
                              ans_b = br;
                        }
                  }
            }

            cout << ans_g << " "  << ans_s << " " << ans_b << endl;
      }



      return 0;
}
