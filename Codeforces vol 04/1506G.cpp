#include<bits/stdc++.h>
#define ll long long int

using namespace std;

string ans;

void rec(string s, int sz)
{
      ll n = s.size();
      vector<int> G[30];

      for (int i=0 ; i<n ; i++){
            ll temp = s[i]-'a';
            G[temp].push_back(i);
      }

      int cnt[n+5];
      memset(cnt, 0, sizeof cnt);

      set<char> st;
      for (int i=n-1 ; i>=0 ; i--){
            st.insert(s[i]);
            cnt[i] = st.size();
      }

      for (int i=25 ; i>=0 ; i--){
            bool brk = false;
            for (int j= 0 ;j<G[i].size() ; j++){
                  if (cnt[G[i][j]] == sz){
                        ans.push_back(s[G[i][j]]);

                        int id = G[i][j];
                        string s_new = "";
                        for (int k = id ; k<n ; k++){
                              if (s[k]!=s[id])s_new.push_back(s[k]);
                        }
                        rec(s_new, sz-1);
                        return;
                  }
            }
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            string s;
            cin >> s;
            set<char> st;

            for (int i=0; i<s.size() ; i++){
                  st.insert(s[i]);
            }
            ans = "";
            rec(s,st.size());
            cout << ans << "\n";
      }

      return 0;
}
