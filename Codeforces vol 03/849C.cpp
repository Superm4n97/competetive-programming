#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s;

int main()
{
      ll n , temp = 0 , sum = 0;
      char ch = 'a';

      cin >> n;

      if (n==0){
            cout << 'a' << endl;
            return 0;
      }

      while(sum<n){
            if (sum+temp>n){
                  ch++;
                  temp = 0;
            }

            s.push_back(ch);
            sum+=temp;
            temp++;
      }

      //show(sum);


      cout << s << endl;


      return 0;
}
/**

**/

