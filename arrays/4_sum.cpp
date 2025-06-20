// have to find all the elements sum up to target

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// BRUTE
// try out all the possible combinations
// TC : O(n^4); SC : 2*O(no. of unique quads)
// std::vector<std::vector<int>> foursum(std::vector<int> vec, int target){
//       int n = vec.size();
//       std::set<std::vector<int>> st;
//       for(int i = 0; i < n-3; i++){
//             for(int j = i+1; j < n-2; j++){
//                   for(int k = j+1; k < n-1; k++){
//                         for(int l = k+1; l < n; l++){
//                               long long sum = vec[i] + vec[j];
//                               sum += vec[k];
//                               sum += vec[l];
//                               if(sum == target){
//                                     std::vector<int> temp = {vec[i], vec[j], vec[k], vec[l]};
//                                     std::sort(temp.begin(), temp.end());
//                                     st.insert(temp);
//                               }
//                         }
//                   }
//             }
//       }
//       std::vector<std::vector<int>> ans(st.begin(), st.end());
//       return ans;
// }

// BETTER
// use of hashset
// TC : O(n^3 * logm); SC : O(n) + 2*O(no. of unique quads)
// m is variable size of set
// std::vector<std::vector<int>> foursum(std::vector<int> vec, int target){
//       int n = vec.size();
//       std::set<std::vector<int>> st;
//       for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                   std::set<long long> hashset;
//                   for(int k = j+1; k < n; k++){
//                         long long sum = vec[i] + vec[j] + vec[k];
//                         long long fourth = target - sum;
//                         if(hashset.find(fourth) != hashset.end()){
//                               std::vector<int> temp = {vec[i], vec[j], vec[k], (int)fourth};
//                               std::sort(temp.begin(), temp.end());
//                               st.insert(temp);
//                         }
//                         hashset.insert(vec[k]);
//                   }
//             }
//       }
//       std::vector<std::vector<int>> ans(st.begin(), st.end());
//       return ans;
// }

// OPTIMAL
//  TC : O(n^3); SC : O(no. of quads)
std::vector<std::vector<int>> foursum(std::vector<int> vec, int target){
      int n = vec.size();
      std::vector<std::vector<int>> ans;
      sort(vec.begin(), vec.end());
      for(int i = 0; i < n; i++){
            if(i > 0 && vec[i] == vec[i-1]) continue;
            for(int j = i+1; j < n; j++){
                  if(j  != (i+1) && vec[j] == vec[j-1]) continue;
                  int k = j+1;
                  int l = n-1;
                  while(k < l){
                        long long sum = vec[i];       // add this way cause the number might be long
                        sum += vec[j];
                        sum += vec[k]; 
                        sum += vec[l];
                        if(sum == target){
                              std::vector<int> temp = {vec[i], vec[j], vec[k], vec[l]};
                              ans.push_back(temp);
                              k++;
                              l--;
                              while(k < l && vec[k] == vec[k-1]) k++;
                              while(k < l && vec[l] == vec[l+1]) l--;
                        }
                        else if(sum < target) k++;
                        else l--;
                  }
            }
      }
      return ans;
}

int main(){
      std::vector<int> vec = {1, 0, -1, 0, -2, 2};
      // std::vector<int> vec = {2, 2, 2, 2, 2};
      int target = 0;
      std::vector<std::vector<int>> ans = foursum(vec, target);
      for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                  std::cout << ans[i][j] << "\t";
            }
            std::cout << "\n";
      }
      return 0;
}