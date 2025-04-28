#include <bits/stdc++.h>
using namespace std;

// BRUTE
// just sort the array directly
// TC : O(nlogn); SC : O(n) -> for merge sort

/* ---------------------------------------------------------------- */

// BETTER
// TC : O(2n); SC : O(1)
class Solution {
      public:
            void sortColors(vector<int>& nums) {
                  int n = nums.size();
                  int zero = 0, one = 0, two = 0;
            
                  for(int i = 0; i < n; i++){
                        if(nums[i] == 0) zero++;
                        else if(nums[i] == 1) one++;
                        else two++;
                  }
            
                  for(int i = 0; i < zero; i++) nums[i] = 0;
                  for(int i = zero; i < zero+one; i++) nums[i] = 1;
                  for(int i = zero+one; i < zero+one+two; i++) nums[i] = 2;   
            }
};

/* ---------------------------------------------------------------- */

// OPTIMAL
// DUTCH NATIONAL FLAG ALGORITHM
// TC : O(n); SC : (1)
class Solution {
      public:
            void sortColors(vector<int>& nums) {
                  int n = nums.size();
            
                  int low = 0;
                  int mid = 0;
                  int high = n-1;
            
                  while(mid <= high){
                        if(nums[mid] == 0){
                        swap(nums[low], nums[mid]);
                        low++;
                        mid++;
                        }
                        else if(nums[mid] == 1){
                        mid++;
                        }
                        else{
                        swap(nums[mid], nums[high]);
                        high--;
                        }
                  }
            }
};