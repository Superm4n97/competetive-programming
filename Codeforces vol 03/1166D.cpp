#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll a, b, m;
            cin >> a >> b >> m;

            if (b-a<=m){
                  if (a==b)cout << "1 " << a << endl;
                  else cout << "2 " <<  a << " " << b << endl;
                  continue;
            }

            vector < ll > ans;

            ll temp = a , off = 1;
            while(temp+off<=b){
                  ans.push_back(temp+off);
                  temp*=2;
                  off*=2;
            }

            reverse(ans.begin(),ans.end());

            ll cnt = ans.size()+1 , remaining = b - ans[0];
            m--;

            while(cnt--){
                  vector < ll > v;

                  ll temp = m;

                  for (int i=0 ; i<cnt ; i++){

                        if (remaining<=m || temp>remaining)break;

                        if (i<1){
                              v.push_back(m);
                              //remaining-=m;
                        }
                        else {
                              v.push_back(temp);
                              //remaining-=temp;
                              temp*=2;
                        }
                  }

                  if (!v.empty()) {
                        reverse(v.begin(),v.end());
                        remaining-=v[0];
                  }

                  //for (int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
                  //cout << endl;

                  for (int i=0 ; i<v.size() ; i++){
                        ans[i]+=v[i];
                  }

                  if (remaining<=m && cnt>1){

                        ans[0]+=remaining;
                        remaining = 0;
                        break;
                  }
            }

            //show(remaining);

            if (remaining>0)cout << -1 << endl;
            else {
                  cout << ans.size()+1 << " " << a << " ";
                  for (int i=ans.size()-1 ; i>=0 ; i--){
                        cout << ans[i] << " ";
                  }
                  cout << endl;
            }
      }


      return 0;
}
