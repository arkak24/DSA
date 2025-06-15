// have to find the longest sequence that can be found

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>

// BRUTE
// pick an element, check the whle array for the next element
// if found then increase the counter and check for the next again
// do for all the elements in the array
// TC : O(n^2); SC : O(1)
// bool linear_search(std::vector<int> vec, int target){
//       for(int i = 0; i < vec.size(); i++){
//             if(vec[i] == target){
//                   return true;
//             }
//       }
//       return false;
// }
// int longest_consecutive_sequence(std::vector<int> vec){
//       int longest = 1;
//       for(int i = 0; i < vec.size(); i++){
//             int x = vec[i];
//             int count = 1;
//             while(linear_search(vec, x+1) == true){
//                   x = x+1;
//                   count = count+1;
//             }
//             longest = std::max(longest, count);
//       }
//       return longest;
// }

// BETTER
// int longest_consecutive_sequence(std::vector<int> vec){
//       std::sort(vec.begin(), vec.end());
//       int longest = 1;
//       int count = 0;
//       int last_smallest = INT_MIN;
//       for(int i = 0; i < vec.size(); i++){
//             if(vec[i]-1 == last_smallest){
//                   count += 1;
//                   last_smallest = vec[i];
//             }
//             else if(vec[i] != last_smallest){
//                   count = 1;
//                   last_smallest = vec[i];
//             }
//             longest = std::max(longest, count);
//       }
//       return longest;
// }

// OPTIMAL
int longest_consecutive_sequence(std::vector<int> vec){
      if(vec.size() == 0) return 0;
      int longest = 1;
      std::unordered_set<int> st;
      for(int i = 0; i < vec.size(); i++){
            st.insert(vec[i]);
      }
      for(auto it : vec){
            if(st.find(it-1) == st.end()){
                  int count = 1;
                  int x = it;
                  while(st.find(x+1) != st.end()){
                        x = x+1;
                        count = count+1;
                  }
                  longest = std::max(longest, count);
            }
      }
      return longest;
}

int main(){
      std::vector<int> vect = {102, 4, 100, 1, 101, 3, 2, 1, 1};
      int ans =  longest_consecutive_sequence(vect);
      std::cout << ans << std::endl;
      return 0;
}