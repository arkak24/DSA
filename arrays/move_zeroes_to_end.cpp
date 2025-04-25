#include <bits/stdc++.h>

using namespace std;

// BRUTE
// put all the non zero element to temp array -> move them back to original -> put 0's at end
// TC : O(2n); SC : O(n)
// void zeroes_to_end(vector<int> &vect){
//       vector<int> non_zero;

//       // put the non zero to temp array
//       for(int i = 0; i < vect.size(); i++){
//             if(vect[i] != 0){
//                   non_zero.emplace_back(vect[i]);
//             }
//       }
//       // put them back to the original array
//       for(int i = 0; i < non_zero.size(); i++){
//             vect[i] = non_zero[i];
//       }
//       // put zeroes at the end
//       for(int i = non_zero.size(); i < vect.size(); i++){
//             vect[i] = 0;
//       }
// }

/* ------------------------------------------------------------------------------------ */

// OPTIMAL
// use a 2 pointer approach
// TC : O(n); SC : O(1)
void zeroes_to_end(vector<int> &vect){
      int i = 0;

      for(int j = 0; j < vect.size(); j++){
            if(vect[j] != 0){
                  vect[i] = vect[j];
                  if(i != j){
                        vect[j] = 0;
                  }
                  i++;
            }
      }
}

int main(){
      vector<int> vec = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
      zeroes_to_end(vec);
      for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << "\t";
      }
      return 0;
}