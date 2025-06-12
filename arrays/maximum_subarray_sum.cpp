// have to find the maximum subarray sum

#include <iostream>
#include <climits>
#include <vector>

// BRUTE
// explore all the subarrays and then find the maximum
// TC : O(n^3); SC : O(1)
// int maxSubSum(std::vector<int> vec){
//       int n = vec.size();
//       int maximum = INT_MIN;
//       for(int i = 0; i < n; i++){
//             for(int j = i; j < n; j++){
//                   int sum = 0;
//                   for(int k = i; k <= j; k++){
//                         sum = sum + vec[k];
//                   }
//                   maximum = std::max(maximum, sum);
//             }
//       }
//       return maximum;
// }

// BETTER
// from the previous code we can see that we can just add the next element
// coming up in the second loop
// so we dont have to run a third loop explicitely
// int maxSubSum(std::vector<int> vec){
//       int n = vec.size();
//       int maximum = INT_MIN;
//       for(int i = 0; i < n; i++){
//             int sum = 0;
//             for(int j = i; j < n; j++){
//                   sum = sum + vec[j];
//                   maximum = std::max(maximum, sum);
//             }
//       }
//       return maximum;
// }

// OPTIMAL -> KADANE'S ALGORITHM
// TC : O(n); SC : O(1)
int maxSubSum(std::vector<int> vec){
      int sum = 0;
      int maximum = INT_MIN;

      int n = vec.size();
      for(int i = 0; i < n; i++){
            sum = sum + vec[i];
            if(sum > maximum){
                  maximum = sum;
            }
            if(sum < 0){
                  sum = 0;
            }
      }
      return maximum;
}

int main(){
      std::vector<int> vect;
      vect = {-2, -3, 4 , -1, -2, 1, 5, -3};

      int ans = maxSubSum(vect);

      std::cout << "The maximum subarray sum is " << ans << std::endl;

      return 0;
}