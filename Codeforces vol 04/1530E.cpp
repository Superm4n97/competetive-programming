#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

ll charNeeded(ll k, ll small)
{
      ll rem = small - k-1;
      ll ret = (rem+(k-1))/k;
      return ret;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            string s;
            cin >> s;
            sort(s.begin(),s.end());
            ll small= 1 , n = s.size();
            for (int i=1 ; i<n ; i++){
                  if (s[i]==s[i-1])small++;
                  else break;
            }

            ll others = n-small, mn = n+1 , cnt = n, min_id;

            for (int i=small ; i<n ; i++){
                  if (s[i]!=s[i-1]){
                        if (mn>cnt){
                              mn = cnt;
                              min_id = i-cnt;
                        }
                              cnt = 1;
                  }
                  else cnt++;

                  if (i==n-1){
                        if (cnt<mn){
                              mn = cnt;
                              min_id = i-cnt+1;
                        }
                  }
            }

//            show(mn);

            if (small==1){
                  cout << s << endl;
                  continue;
            }

            if (mn == 1){//baaacccdd
                  cout << s[min_id];
                  for (int i=0 ; i<n ; i++){
                        if (i==min_id)continue;
                        cout << s[i];
                  }
                  cout << endl;
            }
            else if (small-2<=others){//aababacacdd
                  cout << s[0] << s[1];
                  small-=2;
                  for (int i=small+2 ; i<n ; i++){
                        cout << s[i];
                        if (small){
                              cout << s[0];
                              small--;
                        }
                  }
                  cout << endl;
            }
            else {
                  if (small==n)cout << s << endl;//aaaaaaa
                  else{//aaaaaaaabbbccc aaaaaaaabb

                        set<char>st;
                        int _3rd = -1;
                        for (int i=0 ; i<n ; i++){
                              st.insert(s[i]);
                              if (st.size()==3 && _3rd==-1){
                                    _3rd = i;
                              }
                        }
                        //aaaaaaaabbc
                        //
                        if (st.size()>=3){
                              swap(s[1],s[small]);
                              swap(s[small+1],s[_3rd]);
                              cout << s << endl;
                        //aaabaabaabaa
                        //aaabaabaabaaa
                        //abaaaaaaaaabb
                        }
                        else {
                              cout <<s[0];
                              for (int i=small ; i<n ; i++)cout << s[i];
                              for (int i=1 ; i<small ; i++)cout << s[i];
                              cout << endl;
                        }
                  }
            }
      }


      return 0;
}
