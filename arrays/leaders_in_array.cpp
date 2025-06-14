// have to find the leader elements
// all the elements on the right side of the leader element is smalleer than the leader element
// the last element is always a leader element

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// BRUTE
// take element and do linear search on the right of it
// std::vector<int> leader_elements(std::vector<int> vect){
//       std::vector<int> ans;
//       for(int i = 0; i < vect.size(); i++){
//             bool leader = true;
//             for(int j = i+1; j < vect.size(); j++){
//                   if(vect[j] > vect[i]){
//                         leader = false;
//                         break;
//                   }
//             }
//             if(leader == true){
//                   ans.emplace_back(vect[i]);
//             }
//       }
//       return ans;
// }

// OPTIMAL
// choose an element, if that element is greater than the maximum of all the leemnt present in the right
// then that choosen element is a leader element
// TC : O(n); SC : O(n) -> for returning the answer
std::vector<int> leader_elements(std::vector<int> vect){
      std::vector<int> ans;
      int maxi = INT_MIN;
      for(int i = vect.size()-1; i >= 0; i--){
            if(vect[i] > maxi){
                  ans.emplace_back(vect[i]);
            }
            maxi = std::max(maxi, vect[i]);
      }
      std::reverse(ans.begin(), ans.end());
      return ans;
}

int main(){
      std::vector<int> vect = {10, 22, 12, 3, 0, 6};
      std::vector<int> ans = leader_elements(vect);

      for(auto it : ans){
            std::cout << it << "\t";
      }
      std::cout << "\n";
      return 0;
}