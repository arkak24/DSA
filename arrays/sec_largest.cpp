#include <bits/stdc++.h>
using namespace std;

// BRUTE
// sort the array and then find the second largest
// int second_largest(vector<int> vect){

//       sort(vect.begin(), vect.end());

//       int n = vect.size();
//       int largest = vect[n-1];
//       int sec_largest;
//       for(int i = n-2; i >=0 ;i--){
//             if(vect[i] != largest){
//                   sec_largest = vect[i];
//                   break;
//             }
//       }            
//       return sec_largest;
// }

/* ------------------------------------------------------------------------------------------ */

// BETTER
// find the largest and then compare to find the second largest
// int second_largest(vector<int> vect){
//       int largest = -1;       // take largest if array contains negative numbers
//       for(int i = 0; i < vect.size(); i++){
//             if(largest < vect[i]){
//                   largest = vect[i];
//             }
//       }

//       int sec_largest = -1;
//       for(int i = 0; i < vect.size(); i++){
//             if((sec_largest < vect[i]) && (vect[i] != largest)){
//                   sec_largest = vect[i];
//             }
//       }
//       return sec_largest;
// }

/* ------------------------------------------------------------------------------------------ */

// OPTIMAL
// find the largest and the second largest simultaneously
int second_largest(vector<int> vect){
      int largest = vect[0];
      int sec_largest = -1;
      for(int i = 0; i < vect.size(); i++){
            if(largest < vect[i]){
                  sec_largest = largest;
                  largest = vect[i];
            }
            else if(vect[i] < largest && vect[i] > sec_largest){
                  sec_largest = vect[i]; 
            }
      }
      return sec_largest;
}

int main(){
      vector<int> vec = {1, 2, 4, 7, 7, 5};
      int ans = second_largest(vec);
      cout << ans;
      return 0;
}