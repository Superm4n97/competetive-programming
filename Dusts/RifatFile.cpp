#include<bits/stdc++.h>
#define ll long long int

using namespace std;

char intToHex(int a)
{
      char ret = '0';
      if (a<10)ret = '0'+a;
      else {
            a -= 10;
            ret = 'a'+a;
      }
      return ret;
}

int hexTOInt(char ch)
{
      if (ch>='0' && ch<='9')return (int)ch-'0';
      else {
            return (int) (ch-'a')+10;
      }
}


string stringXOR(string s , string t)
{
      int n = s.size() , m = t.size();
      string ret;

      for (int i=1 ; i<=max(n,m) ; i++){
            char c1 = '0',c2 = '0';
            if (n-i>=0)c1 = s[n-i];
            if (m-i>=0)c2 = t[m-i];
            int a = hexTOInt(c1)^hexTOInt(c2);
            ret.push_back(intToHex(a));
      }
      reverse(ret.begin(),ret.end());
      return ret;
}

int main()
{
      ifstream myfileRead("input.txt");
      ofstream myfileWrite;
      myfileWrite.open ("output.txt");

      int cnt = 0;
      while(true){
            string s;
            myfileRead>>s;
            if (s=="*")break;

            for (int i=0 ; i<=15 ; i++){
                  for (int j=0 ; j<=15 ; j++){
                        string temp = "00";
                        temp[0] = intToHex(i);
                        temp[1] = intToHex(j);
                        myfileWrite<< stringXOR(s,temp) << "\n";
                  }
            }
      }

      //myfileWrite.close();
}
