// have to find the number which is missing and repeating in the array
// array containg number form 1 to n

#include <iostream>
#include <vector>
#include <utility>

// BRUTE
// check for all the elemenets iterating in the array
// TC : O(n^2); SC : O(1)
// std::pair<int, int> missing_repeating(std::vector<int> &nums){
//       int repeating = -1;
//       int missing = -1;
//       for(int i = 1; i <= nums.size(); i++){
//             int count = 0;
//             for(int j = 0; j < nums.size(); j++){
//                   if(nums[j] == i){
//                         count++;
//                   }
//             }
//             if(count == 2){
//                   repeating = i;
//             }
//             else if(count == 0){
//                   missing = i;
//             }
//             if(repeating != -1 && missing != -1){
//                   return {missing, repeating};
//             }
//       }
//       return {-1, -1};
// }

// BETTER
// hashing
// TC : O(2n); SC : O(n+1)
// std::pair<int, int> missing_repeating(std::vector<int> &nums){
//       int n = nums.size();
//       int repeating = -1;
//       int missing = -1;
//       std::vector<int> hash(n+1, 0);
//       for(int i = 0; i < n; i++){
//             hash[nums[i]]++;
//       }
//       for(int i = 1; i < n+1; i++){
//             if(hash[i] == 2){
//                   repeating = i;
//             }
//             else if(hash[i] == 0){
//                   missing = i;
//             }
//             if(repeating != -1 && missing != -1){
//                   break;
//             }
//       }
//       return {missing, repeating};
// }

// OPTIMAL 1
// using basic math, series sum formula, derive eqn and apply
// (n*(n+1))/2       (n*(n+1)*((2*n)+1))/6
long long sum_arr(std::vector<int> &nums){
      int n = nums.size();
      long long sum = 0;
      for(int i = 0; i < n; i++){
            sum = sum + nums[i];
      }
      return sum;
}
long long square_sum_arr(std::vector<int> &nums){
      int n = nums.size();
      long long sum = 0;
      for(int i = 0; i < n; i++){
            int temp = nums[i]*nums[i];
            sum = sum + temp;
      }
      return sum;
}
std::pair<int, int> missing_repeating(std::vector<int> &nums){
      int n = nums.size();
      long long Sn = (n*(n+1))/2;
      long long S1 = sum_arr(nums);
      long long Sn2 = (n*(n+1)*((2*n)+1))/6;
      long long S2 = square_sum_arr(nums);

      long long diff = Sn-S1;
      long long diff_sq = Sn2-S2;

      long long missing = (diff+(diff_sq/diff))/2;
      long long repeating = missing-diff;
      return {missing, repeating};
}

int main(){
      // std::vector<int> vec = {4, 3, 6, 2, 1, 1};
      std::vector<int> vec = {1, 2, 2, 4, 5};
      std::pair<int, int> ans = missing_repeating(vec);
      std::cout << "Missing = " << ans.first << std::endl;
      std::cout << "Repeating = " << ans.second << std::endl;
      return 0;
}