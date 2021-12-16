#include<bits/stdc++.h>
using namespace std;

int main()
{
      string s = ")))((";

      int cnt = 0 , mn = 0;

      for (int i=0 ; i<s.size() ; i++){
            if (s[i]==')')cnt--;
            else cnt++;

            if (cnt<mn)mn = cnt;
      }

      int ans = abs(mn) + (cnt+abs(mn));

      printf("%d\n",ans);

}
