// have to find the number of subarray present in an array with sum k

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// BRUTE
// generate all the subarrays and check if the sum of all the elements in that subarray equals to target
// TC : O(n^3); SC : O(1)
// int number_of_subarrays(std::vector<int> vec, int target){
//       int count = 0;
//       for(int i = 0; i < vec.size(); i++){
//             for(int j = i; j < vec.size(); j++){
//                   int sum = 0;
//                   for(int k = i; k <= j; k++){
//                         sum += vec[j];
//                   }
//                   if(sum == target){
//                         count++;
//                   }     
//             }
//       }
//       return count;
// }

// BETTER
// TC : O(N^2); SC : O(1)
// int number_of_subarrays(std::vector<int> vec, int target){
//       int count = 0;
//       for(int i = 0; i < vec.size(); i++){
//             int sum = 0;
//             for(int j = i; j < vec.size(); j++){
//                   sum += vec[j];
//                   if(sum == target){
//                         count++;
//                   }     
//             }
//       }
//       return count;
// }

int number_of_subarrays(vector<int> vect, long long k){
      std::unordered_map<int, int> mpp;
      mpp[0] = 1;
      int preSum = 0;
      int count = 0;
      for(int i = 0; i < vect.size(); i++){
            preSum += vect[i];
            int remove = preSum - k;
            count = count + mpp[remove];
            mpp[preSum] += 1;
      }
      return count;
}

int main(){
      std::vector<int> vect = {1, 2, -3, 3, 1, 1, 1, 4, 2, -3};
      int k = 3;

      int ans = number_of_subarrays(vect, k);
      std::cout << ans << endl;

      return 0;
}