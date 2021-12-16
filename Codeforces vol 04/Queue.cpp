#include<bits/stdc++.h>

using namespace std;

int main()
{
      queue < int > myqueue;

      myqueue.push(5);
      myqueue.push(2);
      myqueue.push(3);
      myqueue.push(7);

      ///myqueue.empty()

      while(!myqueue.empty()){
            cout << myqueue.front() << " ";
            myqueue.pop();
      }



      return 0;
}
