#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define type _type

using namespace std;

ll type(string s)
{
      if (s.size()==1){
            if (s[0]=='0')return 0LL;
            else return 3LL;
      }
      if (s[0]=='0' && s[s.size()-1]=='0')return 0LL;
      if (s[0]=='0' && s[s.size()-1]=='1')return 1LL;
      if (s[0]=='1' && s[s.size()-1]=='0')return 2LL;
      return 3LL;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            vector < string > vstr;
            map < string , ll > mp , id;
            ll fix[n+5] , ok[5];
            memset(fix,0,sizeof fix);
            memset(ok,0,sizeof ok);
            bool solution = true;
            vector < ll > ans , cnt[5];


            for (int i=0 ; i<n;i++){

                  string s;
                  cin >> s;

                  if (mp[s]>1){

                        solution = false;
                  }
                  else if (mp[s]==1){

                        string rs = s;
                        reverse(rs.begin() , rs.end());

                        if (mp[rs]!=0)solution = false;
                        else {
                              mp[rs] = 1;
                              vstr.push_back(rs);
                              id[rs] = i;

                              ans.push_back(i+1);

                              fix[i] = 1;
                              fix[id[s]] = 1;
                        }
                  }
                  else {
                        mp[s] = 1;
                        id[s] = i;
                        vstr.push_back(s);

                        string rs = s;
                        reverse(rs.begin() , rs.end());

                        if(mp[rs]!=0){
                              fix[i] = 1;
                              fix[id[rs]] = 1;
                        }

                  }
            }

            if (!solution){
                  cout << -1 << endl;
                  continue;
            }

            //show("1");

            for (int i=0 ; i<n; i++){
                  ok[type(vstr[i])] = 1;

                  if (!fix[i]){
                        cnt[type(vstr[i])].push_back(i+1);
                  }
            }

            if (ok[0] != 0 && ok[3] != 0){
                  if (ok[1]==0 && ok[2]==0){

                        cout << -1 << endl;
                        continue;
                  }
            }


            ll temp = (ll)cnt[1].size()-cnt[2].size();

            if (temp>1){
                  temp/=2;
                  //    show(temp);
                  for (int i=0 ;i<temp ; i++){
                        ans.push_back(cnt[1][i]);
                  }
            }
            else if (temp<1){

                  temp*=-1;
                  temp/=2;
                  for (int i=0 ;i<temp ; i++){
                        ans.push_back(cnt[2][i]);
                  }
            }

            cout << ans.size() << endl;
            for (int i=0 ; i<ans.size();i++)cout << ans[i] << " ";
            cout << endl;
      }


      return 0;
}

