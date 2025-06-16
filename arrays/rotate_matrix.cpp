// rotate matrix 90 degrees clockwise

#include <iostream>
#include <vector>
#include <algorithm>

// BRUTE
// analyse the final position of the elements
// TC : O(n^2); SC : O(n^2)
// std::vector<std::vector<int>> rotate_matrix(std::vector<std::vector<int>> &matrix){
//       int n = matrix.size();
//       std::vector<std::vector<int>> ans(n, std::vector<int>(n));
//       for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                   ans[j][n-1-i] = matrix[i][j];
//             }
//       }
//       return ans;
// }

// OPTIMAL
// transpose then reverse each row
// TC : O(n^2); SC : O(1)
void rotate_matrix(std::vector<std::vector<int>> &matrix){
      int n = matrix.size();
      for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                  std::swap(matrix[i][j], matrix[j][i]);
            }
      }
      for(int i = 0; i < n; i++){
            std::reverse(matrix[i].begin(), matrix[i].end());
      }
}

int main(){
      int order;
      std::cout << "Enter the order of the square matrix : ";
      std::cin >> order;
      std::vector<std::vector<int>> matrix(order, std::vector<int>(order));

      std::cout << "Enter the matrix : " << std::endl;

      for(int i = 0; i < order; i++){
            for(int j = 0; j < order; j++){
                  std::cin >>  matrix[i][j];
            }
      }
      // matrix = rotate_matrix(matrix);

      rotate_matrix(matrix);

      std::cout << "\nThe rotated matrix is : " << std::endl;
      for(int i = 0; i < order; i++){
            for(int j = 0; j < order; j++){
                  std::cout << matrix[i][j] << "\t";
            }
            std::cout << "\n";
      }

      return 0;
}