#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m;

int main()
{
      cin >> n >> m;

      string s[n+5] ;
      for (int i=0 ; i<n ; i++)cin >> s[i];

      if (n>=4 && m>=4){
            cout << -1 << endl;
            return 0;
      }

      if (n==1 || m==1){
            cout << 0 << endl;
            return 0;
      }

      string sa,sb;

      if (n>m){
            if (m==2){
                  for (int i=0 ; i<n ; i++){

                        if ((s[i][0]=='0'&&s[i][1]=='0') || (s[i][0]=='1'&&s[i][1]=='1'))sa.push_back('0');
                        else sa.push_back('1');
                  }
            }
            else {
                  for (int i=0 ; i<n ; i++){

                        if ((s[i][0]=='0'&&s[i][1]=='0') || (s[i][0]=='1'&&s[i][1]=='1'))sa.push_back('0');
                        else sa.push_back('1');

                        if ((s[i][2]=='0'&&s[i][1]=='0') || (s[i][2]=='1'&&s[i][1]=='1'))sb.push_back('0');
                        else sb.push_back('1');
                  }
            }
      }
      else {
            if (n==2){
                  for (int j=0 ; j<m ; j++){

                        if ((s[0][j]=='0'&&s[1][j]=='0')||(s[0][j]=='1'&&s[1][j]=='1'))sa.push_back('0');
                        else sa.push_back('1');
                  }
            }
            else {
                  for (int j=0 ; j<m ; j++){

                        if ((s[0][j]=='0'&&s[1][j]=='0')||(s[0][j]=='1'&&s[1][j]=='1'))sa.push_back('0');
                        else sa.push_back('1');

                        if ((s[2][j]=='0'&&s[1][j]=='0')||(s[2][j]=='1'&&s[1][j]=='1'))sb.push_back('0');
                        else sb.push_back('1');
                  }
            }
      }

      ll x1 = 0 , y1 = 0 , x2 = 0 , y2 = 0 , ans = 10000000000000016;

      if (sb.empty()){

            ll a = 0, b = 0;
            for (int i=0 ;i<sa.size(); i++){
                  if (sa[i]=='0' && i%2==1)a++;
                  if (sa[i]=='1' && i%2==0)a++;

                  if (sa[i]=='0' && i%2==0)b++;
                  if (sa[i]=='1' && i%2==1)b++;
            }
            ans = min(a,b);
      }
      else {

            ll cntx1 = 0 , cntx2 = 0 , cnty1 = 0 , cnty2 = 0;
            for (int i=0 ;i<sa.size(); i++){

                  ll a1 = 0, b1 = 0 ,a2 = 0, b2 = 0;

                  if (sa[i]=='0' && i%2==1)a1++;
                  if (sa[i]=='1' && i%2==0)a1++;

                  if (sa[i]=='0' && i%2==0)b1++;
                  if (sa[i]=='1' && i%2==1)b1++;

                  if (sb[i]=='0' && i%2==1)a2++;
                  if (sb[i]=='1' && i%2==0)a2++;

                  if (sb[i]=='0' && i%2==0)b2++;
                  if (sb[i]=='1' && i%2==1)b2++;

                  if (a1==1 || a2==1)cntx1++;
                  if (a1==1 || b2==1)cntx2++;
                  if (b1==1 || a2==1)cnty1++;
                  if (b1==1 || b2==1)cnty2++;
            }
            ans = min(min(cntx1,cntx2),min(cnty1,cnty2));
      }

      cout <<ans<< endl;


      return 0;
}
