#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#include<string.h>
#include<string>

using namespace std;

ll n , q;

struct node
{
      node* next[27];
      ll endmark;

      node(){
            for (int i=0 ; i<27 ; i++)next[i] = NULL;
            endmark = 0;
      }
};
node* root;

void build(string s)
{
      node* ptr = root;
      for (int i=0 ; i<s.size() ; i++){
            ll eg = s[i]-'a';
            if (ptr->next[eg]==NULL)ptr->next[eg] = new node();
            ptr = ptr->next[eg];
      }
      ptr->endmark++;
//      show(s);
//      show(ptr->endmark);
}

ll quary(string s)
{
      node* ptr = root;
      for (int i = 0 ; i<s.size() ; i++){
            ll eg = s[i]-'a';
            if (ptr->next[eg]==NULL)return 0;
            ptr = ptr->next[eg];
      }
      return ptr->endmark;
}

void DEL(node* ptr)
{
      for (int i=0 ; i<26 ; i++){
            if (ptr->next[i]!=NULL)DEL(ptr->next[i]);
      }
      delete(ptr);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ;_t++){
            root = new node();
            cin >> n;

            for (int i=0 ; i<n ; i++){
                  string s;
                  cin >> s;
                  if (s.size()>2){
                        ll x = s.size();
                        swap(s[1],s[x-1]);
                        sort(s.begin()+2 , s.end());
                  }
                  build(s);
            }
            cout << "Case "<<_t<<":"<<endl;
            cin >> q;
            getchar();
            while(q--){
                  ll ans = 1;
                  char s[100005];
                  gets(s);

                  int l=strlen(s);
                  string t(s,s+l);
                  stringstream ss;
                  ss<<t;

                  while(ss>>t){
                        ll x = t.size();
                        if (t.size()>2){
                              swap(t[1],t[x-1]);
                              sort(t.begin()+2 , t.end());
                        }

                        ans = ans*quary(t);
                        t.clear();
                  }
                  cout << ans << endl;
            }
//            DEL(root);
      }

      return 0;
}
