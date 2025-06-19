#include <bits/stdc++.h>
using namespace std;


// BRUTE
// TC : O(n^2); SC : O(1)
class Solution {
      public:
            vector<int> twoSum(vector<int>& nums, int target) {
                  vector<int> ans;
                  int n = nums.size();
                  for(int i = 0; i < n; i++){
                        for(int j = i+1; j < n; j++){
                        int sum = nums[i] + nums[j];
                        if(sum == target){
                              ans.emplace_back(i);
                              ans.emplace_back(j);
                        }
                        }
                  }
                  return ans;
            }
};

/* ----------------------------------------------------------------------------- */

// BETTER
// using hashing and using an unordered map
// TC : O(n); SC : O(n)
class Solution {
      public:
            vector<int> twoSum(vector<int>& nums, int target) {
                  int n = nums.size();
                  vector<int> ans;
                  unordered_map<int, int> mpp;
                  for(int i = 0; i < n; i++){
                        int curr = nums[i];
                        int complement_curr = target - curr;
                        if(mpp.find(complement_curr) != mpp.end()){
                        ans.emplace_back(i);
                        ans.emplace_back(mpp[complement_curr]);
                        }
                        mpp[curr] = i;
                  }
                  return ans;
            }
};

/* ----------------------------------------------------------------------------- */

// OPTIMAL
// only if asked to check if two such pair exists or not
// TC : O(n + nlogn); SC : O(1) -> if array distortion allowed, else SC : O(n)
class Solution {
      public:
            bool twoSum(vector<int>& nums, int target) {
                  int n = nums.size();
                  int left = 0;
                  int right = n-1;
                  while(left < right){
                        int sum = nums[left] + nums[right];
                        if(sum == target){
                              return true;
                        }
                        if(sum < target){
                              left++;
                        }
                        if(sum > target){
                              right--;
                        }
                  }
                  return false;
            }
};