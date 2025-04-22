#include <bits/stdc++.h>
using namespace std;

// BRUTE -> TC O(nlogn + n); SC O(n)
// put the unique element in set as set only takes unique element 
// replace array's elements with set's
// void remove_duplicate(vector<int> &vect){
//       set<int> st;
//       for(int i = 0; i < vect.size(); i++){
//             st.insert(vect[i]);
//       }
//       int idx = 0;
//       for(auto it : st){
//             vect[idx] = it;
//             idx++;
//       }
// }

// BETETR -> TC O(n)
// use a 2 pointer approach
void remove_duplicate(vector<int> &vect){
      int i = 0;
      for(int j = 1;  j < vect.size(); j++){
            if(vect[j] != vect[i]){
                  vect[i+1] = vect[j];
                  i++;
            }
      }
}

int main(){
      vector<int> vec = {1, 1, 2, 2, 2, 3, 3};
      remove_duplicate(vec);
      for(int i = 0; i < vec.size(); i++){
            cout << vec[i];
      }
      return 0;
}