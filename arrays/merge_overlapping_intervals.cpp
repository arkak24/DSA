#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

// BRUTE
// make the intervals closer then check if the next[first] lie inside the current[last]
// TC : O(n.logn + 2n); SC : O(n)
// std::vector<std::vector<int>> merge(std::vector<std::vector<int>> matrix){
//       int n = matrix.size();
//       std::sort(matrix.begin(), matrix.end());
//       std::vector<std::vector<int>> ans;
//       for(int i = 0; i < n; i++){
//             int start = matrix[i][0];
//             int end = matrix[i][1];
//             if(!ans.empty() && end <= ans.back()[1]){
//                   continue;
//             }
//             for(int j = i+1; j < n; j++){
//                   if(matrix[j][0] <= end){
//                         end = std::max(end, matrix[j][1]);
//                   }
//                   else{
//                         break;
//                   }
//             }
//             ans.push_back({start, end});
//       }
//       return ans;
// }

// OPTIMAL
// almost same approach as BETTER
// TC : O(n.logn + n); SC : O(n)
std::vector<std::vector<int>> merge(std::vector<std::vector<int>> matrix){
      int n = matrix.size();
      std::sort(matrix.begin(), matrix.end());
      std::vector<std::vector<int>> ans;
      for(int i = 0; i < n; i++){
            if(ans.empty() || matrix[i][0] > ans.back()[1]){
                  ans.push_back(matrix[i]);
            }
            else{
                  ans.back()[1] = std::max(ans.back()[1], matrix[i][1]);
            }
      }
      return ans;
}

int main(){
      int rows;
      std::cout << "Enter the numebr of rows : ";
      std::cin >> rows;
      std::vector<std::vector<int>> matrix;
      std::cout << "Enter the starting and ending indexes : ";
      for(int i = 0; i < rows; i++){
            int a, b;
            std::cin >> a >> b;
            matrix.push_back({a, b});    // or push_back({a, b});
      }
      std::vector<std::vector<int>> ans = merge(matrix);

      for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                  std::cout << ans[i][j] << "\t";
            }
            std::cout << "\n";
      }
      return 0;
}