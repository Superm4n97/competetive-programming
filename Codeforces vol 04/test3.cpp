#include<bits/stdc++.h>
using namespace std;

int main()
{
      int fahem_A[100],fahem_n1 , fahem_n2,fahem_n , fahem_A1[100] , fahem_A2[100];
      cout << "Size of array 1"<< endl;
      cin >> fahem_n1;
      cout << "Enter Data" << endl;
      for (int i=0 ; i<fahem_n1 ; i++)cin >> fahem_A1[i];

      cout << "Size of array 2" << endl;
      cin >> fahem_n2;
      cout << "Enter Data" << endl;
      for (int i=0 ; i<fahem_n2 ; i++)cin >> fahem_A2[i];

      for (int i=0 ; i<fahem_n1+fahem_n2 ; i++){
            if (i<fahem_n1)fahem_A[i] = fahem_A1[i];
            else fahem_A[i] = fahem_A2[i-fahem_n1];
      }

      fahem_n = fahem_n1+fahem_n2;

      for (int i = 1 ; i<fahem_n ; i++){
            int fahem_temp = fahem_A[i] , j = i-1;
            while(j>=0 && fahem_A[j]<fahem_temp){
                  fahem_A[j+1] = fahem_A[j];
                  j = j-1;
            }
            fahem_A[j+1] = fahem_temp;
      }

      cout << "The sorted aarray is:" << endl;
      for (int i=0 ; i<fahem_n ; i++)cout << fahem_A[i] << " ";
      cout << endl;

      cout << "Enter data to search" << endl;
      int fahem_val;
      cin >> fahem_val;

      int fahem_res1 = fahem_n , fahem_res2 = -1 , fahem_begin = 0 , fahem_end = fahem_n-1;
      while(fahem_begin<=fahem_end){
            int fahem_mid = (fahem_begin+fahem_end)/2;
            if (fahem_A[fahem_mid]<=fahem_val){
                  if (fahem_A[fahem_mid] == fahem_val)fahem_res1 = min(fahem_res1,fahem_mid);
                  fahem_end = fahem_mid-1;
            }
            else {
                  fahem_begin = fahem_mid+1;
            }
      }

      if (fahem_res1==fahem_n){
            cout << fahem_val << " not found" << endl;
            return 0;
      }
      fahem_begin = 0 , fahem_end = fahem_n-1;
      while(fahem_begin<=fahem_end){
            int fahem_mid = (fahem_begin+fahem_end)/2;
            if (fahem_A[fahem_mid]>=fahem_val){
                  if (fahem_A[fahem_mid] == fahem_val)fahem_res2 = max(fahem_res2,fahem_mid);
                  fahem_begin = fahem_mid+1;
            }
            else {
                  fahem_end = fahem_mid-1;
            }
      }
      cout << fahem_val << " is found " << fahem_res2-fahem_res1+1 << " times in the array" << endl;


      return 0;
}
