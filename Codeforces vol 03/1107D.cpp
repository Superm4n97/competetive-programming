#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "<< x << endl

using namespace std;

ll n;
vector < string > G[5204] , v;

string make(char ch)
{
      ll temp;
      if (ch>='0' && ch<='9'){
            temp = ch - '0';
      }
      else {
            ll off = ch - 'A';
            temp = 10+off;
      }

      if (temp==0)return "0000";
      if (temp==1)return "0001";
      if (temp==2)return "0010";
      if (temp==3)return "0011";
      if (temp==4)return "0100";
      if (temp==5)return "0101";
      if (temp==6)return "0110";
      if (temp==7)return "0111";
      if (temp==8)return "1000";
      if (temp==9)return "1001";
      if (temp==10)return "1010";
      if (temp==11)return "1011";
      if (temp==12)return "1100";
      if (temp==13)return "1101";
      if (temp==14)return "1110";
      if (temp==15)return "1111";
}

ll rejudge(string s , ll x)
{
//      show(x);
//      show(s);

      vector < ll > divisor;
      for (int i=1 ; i*i<=n ; i++){
            if (x%i==0){
                  divisor.push_back(i);
                  divisor.push_back(x/i);
            }
      }

      sort(divisor.rbegin() , divisor.rend());

      for (int i=0 ; i<divisor.size()-1 ; i++){
            ll temp = divisor[i] , cnt = 0;
            bool sol = true;

            for (int j = 0 ;j<s.size() ; j++){
                  if (s[j]=='1')cnt++;

                  if ((j+1)%temp==0){
                        if (cnt!=0 && cnt!=temp){
//                              show(j);
//                              show(temp);
//                              show(cnt);
                              sol = false;
                        }
                        cnt=0;
                  }
            }

            if (sol)return temp;
      }
      return 1;
}

int main()
{
      cin >> n;
      for (int i=0 ;i<n; i++){

            string s;
            cin >> s;
            v.push_back(s);
      }

      ll cnt = 1 , x = 100000008;

      for (int i=1 ; i<n ; i++){

            if (v[i]==v[i-1])cnt++;
            else {
                  x = min(x,cnt);
                  cnt = 1;
            }
      }
      x = min(x,cnt);

      if (n%x != 0)x = 1;

      if (x==1){
            cout << x << endl;
            return 0;
      }

      cnt = 1;
      for (int i=1 ; i<n ; i++){

            if (cnt<x && v[i]!=v[i-1]){
                  x = 1;
                  break;
            }

            if (v[i]==v[i-1]){
                  cnt++;
            }

            if (cnt==x){
                  cnt = 1;
                  i++;
            }
      }

      if (x==1){
            cout << x << endl;
            return 0;
      }

      //show(x);


      for (int i=x-1 ; i<n ; i+=x){
            string t = v[i] , s;
            for (int j=0 ; j<t.size() ; j++){
                  string temp = make(t[j]);

                  for (int k = 0 ; k<temp.size() ; k++){
                        s.push_back(temp[k]);
                  }
            }

            cnt = 0;

//            show(s);
//            show(s.size());

            x = rejudge(s , x);

            if (x==1)break;
      }

      cout << x << endl;



      return 0;
}
