#include <iostream>
#include <vector>
#include <map>
#include <climits>

// BRUTE
// traverse through all the elements
// TC : O(n^2); SC : O(2) ~ O(1)
// std::vector<int> majority_element(std::vector<int> vec){
//       std::vector<int> ans;
//       for(int i = 0; i < vec.size(); i++){
//             if(ans.size() == 0 || ans[0] != vec[i]){
//                   int count = 0;
//                   for(int j = 0; j < vec.size(); j++){
//                         if(vec[j] == vec[i]){
//                               count++;
//                         }
//                   }
//                   if(count > vec.size()/3){
//                         ans.emplace_back(vec[i]);
//                   }
//             }
//             if(ans.size() == 2){
//                   break;
//             }
//       }
//       return ans;
// }

// BETTER1
// use hashmap
// TC : O(n.logn + n); SC : (n)
// std::vector<int> majority_element(std::vector<int> vec){
//       std::vector<int> ans;
//       std::map<int, int> mpp;
//       for(int i = 0; i < vec.size(); i++){
//             mpp[vec[i]]++;
//       }
//       for(auto it : mpp){
//             if(it.second > vec.size()/3){
//                   ans.emplace_back(it.first);
//             }
//       }
//       return ans;
// }

// BETTER2
// use hashmap
// std::vector<int> majority_element(std::vector<int> vec){
      // std::vector<int> ans;
      // std::map<int, int> mpp;
      // int temp = int(vec.size()/3) + 1;
      // for(int i = 0; i < vec.size(); i++){
      //       mpp[vec[i]]++;
      //       if(mpp[vec[i]] == temp){      // NOTE
      //             ans.emplace_back(vec[i]);
      //       }
      //       if(ans.size() == 2){
      //             break;
      //       }
      // }
      // return ans;
// }

// OPTIMAL
// similar to MOORE'S VOTING ALGORITHM
// TC : O(2n); SC : O(1)
std::vector<int> majority_element(std::vector<int> vec){
      int count1 = 0, count2 = 0;
      int element1 = INT_MIN;
      int element2 = INT_MIN;
      for(int i = 0; i < vec.size(); i++){
            if(count1 == 0 && element2 != vec[i]){
                  count1 = 1;
                  element1 = vec[i];
            }
            else if(count2 == 0 && element1 != vec[i]){
                  count2 = 1;
                  element2 = vec[i];
            }
            else if(vec[i] == element1){
                  count1++;
            }
            else if(vec[i] == element2){
                  count2++;
            }
            else{
                  count1--;
                  count2--;
            }
      }
      std::vector<int> ans;
      count1 = 0, count2 = 0;
      for(int i = 0; i < vec.size(); i++){
            if(element1 == vec[i]){
                  count1++;
            }
            if(element2 == vec[i]){
                  count2++;
            }
      }
      int mini = (int)(vec.size()/3) + 1;
      if(count1 >= mini){
            ans.push_back(element1);
      }
      if(count2 >= mini){
            ans.push_back(element2);
      }
      return ans;
}

int main(){
      std::vector<int> vec = {1, 1, 2, 1, 3, 3, 2, 3};
      // std::vector<int> vec = {1, 2, 3, 1, 2, 1, 2, 2};
      // std::vector<int> vec = {2, 2};
      std::vector<int> ans = majority_element(vec);
      for(auto it : ans){
            std::cout << it << "\t";
      }
      std::cout << "\n";
      return 0;
}