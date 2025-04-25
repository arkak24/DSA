#include <bits/stdc++.h>

using namespace std;

// this is the optimal only
// TC : O(n)
// SC : O(1) -> for the extra space; O(n) -> for the algorithm
void rotate_one(vector<int> &vect){
      int temp = vect[0];
      for(int i = 0; i < vect.size(); i++){
            vect[i-1] = vect[i];
      }
      vect[vect.size()-1] = temp;
}

int main(){
      vector<int> vec = {1, 2, 3, 4, 5};
      rotate_one(vec);
      
      for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << "\t";
      }

      return 0;
}