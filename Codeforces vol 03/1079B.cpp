#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      string s;
      cin >> s;

      ll n = s.size();

      for (int i=1 ; i<=5 ; i++){

            ll temp = n/i;
            if(temp>20)continue;

            if (n%i==0){
                  cout << i << " " << temp << endl;
                  for (int i=0 ; i<n ; i++){
                        cout << s[i];
                        if ((i+1)%temp == 0)cout << "\n";
                  }

                  return 0;
            }
            if (temp==20)continue;

            ll leftOver = i - (n%i) , prints = 0;

            //show(n);
            //show(leftOver);

            cout << i << " " << temp+1 << endl;
            for (int i=0 ; i<n ; i++){
                  cout << s[i];

                  prints++;

                  if (leftOver && prints==temp){
                        cout << "*";
                        leftOver--;
                        prints++;
                  }
                  if (prints==temp+1){
                        cout << "\n";
                        prints = 0;
                  }
            }
            break;
      }


      return 0;
}
/**

**/
