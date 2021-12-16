#include<bits/stdc++.h>

using namespace std;

///push_back() -> O(1)
///size()
///begin()
///end()
///erase() -> O(N)
///clear()

vector < int > vec;

void Printvector()
{
      for (int i=0 ; i<vec.size() ;i++)cout << vec[i] << " ";
      cout << endl;
}

int main()
{
      vec.push_back(2);
      vec.push_back(5);
      vec.push_back(7);
      vec.push_back(1);
      vec.push_back(3);
      vec.push_back(4);

      Printvector();


      vec.erase(vec.begin()+1,vec.begin()+4);


      Printvector();



      return 0;
}
