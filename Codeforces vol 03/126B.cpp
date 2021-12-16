#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

string s;
ll cnt[maxn], failure[maxn],match[maxn];

int main()
{
      cin >> s;
      failure[1] = failure[0] = 0;

      ll n = s.size();

      if (n>1){
            if (s[0]==s[1]){
                  match[1] = 1;
                  if (n>2)cnt[1] = 1;
            }
      }

      for (int i=2 ; i<s.size() ; i++){
            ll temp = failure[i-1];
//            show(i);aaaabaaaaaaa
//                aaabaacaaa
//                aaxaa
            while(true){
                  if (s[temp]==s[i]){
                        temp = temp+1;
                        break;
                  }
                  if (temp == 0)break;
                  temp = failure[temp];
            }
            failure[i] = temp;
            if (i<n-1){
                  cnt[temp+1] = 1;
            }
      }
      for (int i=0 ; i<s.size() ; i++)
            cout<<failure[i];
      cout << endl;

      ll ans = failure[n-1];
      while(ans!=0 && cnt[ans+1]==0){
            ans = failure[ans];
      }

      if (ans==0){
            ans = -1;
            for (int i=1 ; i<n-1 ; i++)if (s[i]==s[0] && s[i]==s[n-1])ans = 0;
      }

      if (ans>=0){
            for (int i=0 ; i<=ans ; i++)printf("%c",s[i]);
            printf("\n");

      }
      else printf("Just a legend\n");

      return 0;
}
