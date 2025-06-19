// have to find unique triplets whole sum is 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// BRUTE
// try out all the possible combinations
// TC : O(n^3); SC : 2*O(no. of unique triplet)
// std::vector<std::vector<int>> triplet(std::vector<int> vec){
//       int n = vec.size();
//       std::set<std::vector<int>> st;
//       for(int i = 0; i < n-2; i++){
//             for(int j = i+1; j < n-1; j++){
//                   for(int k = j+1; k < n; k++){
//                         if(vec[i]+vec[j]+vec[k] == 0){
//                               std::vector<int> temp = {vec[i], vec[j], vec[k]};
//                               std::sort(temp.begin(), temp.end());
//                               st.insert(temp);
//                         }
//                   }
//             }
//       }
//       std::vector<std::vector<int>> ans(st.begin(), st.end());
//       return ans;
// }

// BETTER
// use of hashset
// TC : O(n^2 * logm); SC : O(n) + 2*O(no. of unique triplets)
// m is variable size of set
// std::vector<std::vector<int>> triplet(std::vector<int> vec){
//       int n = vec.size();
//       std::set<std::vector<int>> st;
//       for(int i = 0; i < n; i++){
//             std::set<int> hashset;
//             for(int j = i+1; j < n; j++){
//                   int third = -(vec[i]+vec[j]);
//                   if(hashset.find(third) != hashset.end()){
//                         std::vector<int> temp = {vec[i], vec[j], third};
//                         std::sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                   }
//                   hashset.insert(vec[j]);
//             }
//       }
//       std::vector<std::vector<int>> ans(st.begin(), st.end());
//       return ans;
// }

// OPTIMAL
// increase decrease approach like in 2 sum problem
// but sort the array at first
// TC : O(n.logn) + O(n^2)
// SC : O(no. of unique triplet) -> for returning the ans
std::vector<std::vector<int>> triplet(std::vector<int> vec){
      int n = vec.size();
      std::vector<std::vector<int>> ans;
      std::sort(vec.begin(), vec.end());
      for(int i = 0; i < n; i++){
            if(i > 0 && vec[i] == vec[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j < k){
                  int sum = vec[i] + vec[j] + vec[k];
                  if(sum < 0){
                        j++;
                  }
                  else if(sum > 0){
                        k--;
                  }
                  else{
                        std::vector<int> temp = {vec[i], vec[j], vec[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j < k && vec[j] == vec[j-1]){
                              j++;
                        }
                        while(j < k && vec[k] == vec[k+1]){
                              k--;
                        }
                  }
            }
      }
      return ans;
}

int main(){
      // std::vector<int> vec = {-1, 0, 1, 2, -1, -4};
      std::vector<int> vec = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
      std::vector<std::vector<int>> ans = triplet(vec);
      for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                  std::cout << ans[i][j] << "\t";
            }
            std::cout << "\n";
      }
      return 0;
}