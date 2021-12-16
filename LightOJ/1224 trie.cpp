#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

struct node
{
      node* next[4];
      int cnt;

      node(){
            cnt = 0;
            for (int i=0; i<4 ; i++)next[i] = NULL;
      }
};
node* root;
ll ans;

ll findDig(char ch)
{
      if (ch=='A')return 0;
      if (ch=='T')return 1;
      if (ch=='C')return 2;
      if (ch=='G')return 3;
}

void insertTrie(string s)
{
      node* ptr = root;
      for (ll i=0; i<s.size() ; i++){
            ll dig = findDig(s[i]);
            if (ptr->next[dig] == NULL)ptr->next[dig] = new node();
            ptr = ptr->next[dig];
            ptr->cnt++;
            ans = max(ans,(i+1) * ptr->cnt);
      }
      return;
}

void deleteTrie(node *ptr)
{
      for (int i=0 ; i<4 ; i++){
            if (ptr->next[i]!=NULL)
                  deleteTrie(ptr->next[i]);
      }
      delete(ptr);
}

int main()
{
      int tc;
      cin >> tc;

      for (int _t = 1 ; _t<=tc ; _t++){

            root = new node();
            ans = 0;

            ll n;
            cin >> n;

            for (int i=0 ; i<n;  i++){
                  string s;
                  cin >> s;
                  insertTrie(s);
            }
            cout << "Case "<<_t<<": " << ans << endl;
            deleteTrie(root);
      }

      return 0;
}
