// we have to find the longest subarray with sum k, the array contains only positive integers

#include <bits/stdc++.h>

using namespace std;

// BRUTE
// generate all the subarrays and check if the sum of all the elements in that subarray equals to target
// TC : O(n^2); SC : O(1)
// int longest_subarray(std::vector<int> vec, int target){

//       int len = 0;
//       for(int i = 0; i < vec.size(); i++){
//             int sum = 0;
//             for(int j = i; j < vec.size(); j++){
//                   sum += vec[j];
//                   if(sum == target){
//                         len = std::max(len, j-i+1);
//                   }     
//             }
//       }
//       return len;
// }

int longest_subarray(vector<int> vect, long long k){
      map<long long, int> preSumMap;
      long long sum = 0;
      int maxLen = 0;
      for(int i = 0; i < vect.size(); i++){
            sum += vect[i];
            if(sum == k){
                  maxLen = max(maxLen, i+1);
            }
            int rem = sum - k;
            if(preSumMap.find(rem) != preSumMap.end()){
                  int len = i - preSumMap[rem];
                  maxLen = max(maxLen, len);
            }
            preSumMap[sum] = i;
      }
      return maxLen;
}

int main(){
      vector<int> vect = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
      int k = 5;

      int ans = longest_subarray(vect, k);
      cout << ans << endl;

      return 0;
}