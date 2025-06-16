// printing the elements of a marix while traversing spirally

#include <iostream>
#include <vector>

std::vector<int> spiral_traversal(std::vector<std::vector<int>> &matrix){
      int n = matrix.size();
      int m = matrix[0].size();
      int left = 0, right = m-1;
      int top = 0, bottom = n-1;

      std::vector<int> ans;

      while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                  ans.emplace_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                  ans.emplace_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){      // for the row matrix
                  for(int i = right; i >= left; i--){
                        ans.emplace_back(matrix[bottom][i]);
                  }
                  bottom--;
            }
            if(left <= right){      // for the column matrix
                  for(int i = bottom; i >= top; i--){
                        ans.emplace_back(matrix[i][left]);
                  }
                  left++;
            }
      }
      return ans;
}

int main(){
      int row, column;
      std::cout << "Enter the number of rows: ";
      std::cin >> row;
      std::cout << "Enter the number of columns: ";
      std::cin >> column;
      std::vector<std::vector<int>> matrix(row, std::vector<int>(column));

      std::cout << "Enter the matrix : " << std::endl;
      for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                  std::cin >> matrix[i][j];
            }
      }

      std::vector<int> ans = spiral_traversal(matrix);

      for(int i = 0; i < ans.size(); i++){
            std::cout << ans[i] << "   ";
      }
      std::cout << "\n";

      return 0;
}