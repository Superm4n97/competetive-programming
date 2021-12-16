#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int

using namespace std;

ll n,k;
string s;
bool ans;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ans = true;

            cin >> n >> k;
            cin >> s;

            queue <ll> q;

            for (int i=0 ; i<n ; i++){
                  if (s[i]!='?')q.push(i);
            }

            while(!q.empty()){

                  ll id = q.front();
                  q.pop();

                  ll id1 = max(-1LL,id-k) , id2 = min(n+1 ,id+k);
                  if (id1>-1){
                        if (s[id1]=='?'){
                              s[id1] = s[id];
                              q.push(id1);
                        }
                        else if (s[id1]!=s[id])ans = false;
                  }
                  if (id2<n){
                        if (s[id2]=='?'){
                              s[id2] = s[id];
                              q.push(id2);
                        }
                        else if (s[id2]!=s[id])ans = false;
                  }
            }

            //show(ans);

            ll one = k/2 , zero = k/2;

            for (int i=0 ; i<k ; i++){
                  if (s[i]=='1'){
                        one--;
                        if (one<0)ans = false;
                  }
                  if (s[i]=='0'){
                        zero--;
                        if (zero<0)ans = false;
                  }
            }

            for (int i=0 ; i<k ; i++){
                  if (s[i]=='?'){
                        if (one)s[i] = '1' , one--;
                        else s[i] = '0' , zero--;
                        q.push(i);
                  }
            }

            if (ans)cout << "YES" << endl;
            else  cout << "NO" << endl;
      }


      return 0;
}
