#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string order;
int fre[30];

string varify(string s)
{
      string t = s;
      for (int i=0 ; i<order.size(); i++){
            for (int j=0 ; j<s.size() ; j++){
                  if (s[j]!='*'){
                        if (s[j]==order[i])s[j] = '*';
                        else t.push_back(s[j]);
                  }
            }
      }
      return t;
}

void process(string s)
{
      order.clear();

      memset(fre,0,sizeof fre);
      for (int i=s.size()-1 ; i>=0 ; i--){
            ll temp = s[i] - 'a';
            if (fre[temp]==0){
                  order.push_back(s[i]);
            }
            fre[temp]++;
      }

      reverse(order.begin(),order.end());

      if (order.size()==1){
            cout << s << " " << s[0] << endl;
      }
      else {
            int mx = 0 , sol = 1;
            for (int i=0 ; i<order.size() ; i++){
                  int temp = order[i]-'a';
                  if (fre[temp]%(i+1)!=0)sol = 0;
                  ll cnt = 0 , lm = fre[temp]/(i+1);
                  for (int j=0 ; j<s.size() ; j++){
                        if (s[j]==order[i]){
                              cnt++;
                              if (lm==cnt){
                                    mx = max(j,mx);
                                    break;
                              }
                        }
                  }
            }

            string st;
            for (int i=0 ; i<=mx ; i++)st.push_back(s[i]);

            if (sol && varify(st)==s){
                  cout << st << " " << order << endl;
            }
            else cout << -1 << endl;
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            string s;
            cin >> s;
            process(s);
      }

      return 0;
}
/*
1
abacaaabaaaaaaa
*/
