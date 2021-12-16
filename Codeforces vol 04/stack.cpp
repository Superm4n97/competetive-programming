#include<bits/stdc++.h>

using namespace std;

int main()
{
      stack < int > st;

      st.push(5);
      st.push(2);
      st.push(3);
      st.push(7);


      while(!st.empty()){
            cout << st.top()<< " ";
            st.pop();
      }




      return 0;
}
