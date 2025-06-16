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

// BETTER 
// TC : O(n.logn) -> ordered map, O(n^2) -> unordered map; SC : O(1)
// this will only work if the array contains only positive integers, excluding 0's
// cause we need longest subarray
// refer to the lec for clear understanding
// int longest_subarray(vector<int> vect, long long k){
//       map<long long, int> preSumMap;
//       long long sum = 0;
//       int maxLen = 0;
//       for(int i = 0; i < vect.size(); i++){
//             sum += vect[i];
//             if(sum == k){
//                   maxLen = max(maxLen, i+1);
//             }
//             long long rem = sum - k;
//             if(preSumMap.find(rem) != preSumMap.end()){        // this means if the rem does exists in the map
//                   int len = i - preSumMap[rem];
//                   maxLen = max(maxLen, len);
//             }
//             preSumMap[sum] = i;
//       }
//       return maxLen;
// }

// BETTER
// TC : O(n); SC : O(1)
// this works for any, including 0's and negatives
// int longest_subarray(vector<int> vect, long long k){
//       map<long long, int> preSumMap;
//       long long sum = 0;
//       int maxLen = 0;
//       for(int i = 0; i < vect.size(); i++){
//             sum += vect[i];
//             if(sum == k){
//                   maxLen = max(maxLen, i+1);
//             }
//             long long rem = sum - k;
//             if(preSumMap.find(rem) != preSumMap.end()){           // this means if the rem does exists in the map
//                   int len = i - preSumMap[rem];
//                   maxLen = max(maxLen, len);
//             }
//             if(preSumMap.find(sum) == preSumMap.end()){           // update the map only if it never existed
//                   preSumMap[sum] = i;
//             }
//       }
//       return maxLen;
// }

// OPTIMAL
// 2 pointer or greedy approach
// TC : O(2n); SC : O(1)
int longest_subarray(vector<int> vect, long long k){
      int left = 0;
      int right = 0;
      long long sum = vect[0];
      int maxlen = 0;
      int n = vect.size();
      while(right < n){
            while(left <= right && sum > k){
                  sum -= vect[left];
                  left++;
            }
            if(sum == k){
                  maxlen = max(maxlen, right-left+1);
            }
            right++;
            if(right < n){
                  sum += vect[right];
            }
      }
      return maxlen;
}

int main(){
      vector<int> vect = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
      int k = 5;

      int ans = longest_subarray(vect, k);
      cout << ans << endl;

      return 0;
}