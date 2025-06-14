// next permutation

#include <iostream>
#include <vector>
#include <algorithm>

// BRUTE
// generate all the permutation in one array in ascending order
// do a linear search to find the index of the given element
// use that index to get the next index and get the ans

// BETTER
// use STL
// TC : O(n); SC : O(1)
// void next_per(std::vector<int> &vect){
//       std::next_permutation(vect.begin(), vect.end());
// }

// OPTIMAL
// worser than STL
// TC : O(3n); SC : O(1)
void next_per(std::vector<int> &vect){
      int n = vect.size();
      int idx = -1;
      for(int i = n-2; i >= 0; i--){
            if(vect[i] < vect[i+1]){
                  idx = i;
                  break;
            }
      }
      if(idx == -1){    // if it is the last and the greatest permutation possible
            std::reverse(vect.begin(), vect.end());
      }
      for(int i = n-1; i >= idx; i--){
            if(vect[i] > vect[idx]){
                  std::swap(vect[i], vect[idx]);
                  break;
            }
      }
      std::reverse(vect.begin()+idx+1, vect.end());
}

int main(){
      std::vector<int> vect = {2, 1, 5, 4, 3, 0, 0};

      next_per(vect);

      for(auto it : vect){
            std::cout << it << "\t";
      }
      std::cout << "\n";
      return 0;
}