// have to find the element appears more than half of the time

#include <iostream>
#include <vector>
#include <map>

// BRUTE
// check for all all the elements individually
// TC : O(n^2); SC : O(1)
// int majority_element(std::vector<int> vec){
//       for(int i = 0; i < vec.size(); i++){
//             int count = 0;
//             for(int j = 0; j < vec.size(); j++){
//                   if(vec[j] == vec[i]){
//                         count++;
//                   }
//             }
//             if(count > vec.size()){
//                   return vec[i];
//             }
//       }
//       return -1;
// }

// BETTER
// use hashing, store <element, count> and then iterate in map to find the majority element
// TC : O(n.logn)+O(n); SC : O(n)
// int majority_element(std::vector<int> vec){
//       std::map<int, int> mpp;
//       for(int i = 0; i < vec.size(); i++){
//             mpp[vec[i]]++;
//       }
//       for(auto it : mpp){
//             if(it.second > vec.size()/2){
//                   return it.first;
//             }
//       }
//       return -1;
// }

// OPTIMAL
// MOORES VOTING ALGORITHM
// apply the algo then again check if it is the majority or not
// TC : O(n) + [O(n) -> this will not be there is it is said that there will be a majority element]; SC : O(1);
int majority_element(std::vector<int> vec){
      int element;
      int count = 0;
      for(int i = 0; i < vec.size(); i++){
            if(count == 0){
                  element = vec[i];
                  count = 1;
            }
            else if(vec[i] == element){
                  count++;
            }
            else{
                  count--;
            }
      }
      int check = 0;
      for(int i = 0; i < vec.size(); i++){
            if(vec[i] == element){
                  check++;
            }
      }
      if(check > vec.size()){
            return element;
      }
      return -1;
}

int main(){
      std::vector<int> vect = {2, 2, 3, 3, 1, 2, 2};
      int ans = majority_element(vect);
      std::cout << ans << std::endl;

      return 0;
}