// have to make the whole row and column 0 if any cell contains 0

#include <iostream>
#include <vector>

// BRUTE
// set to -1 instead of 0 then change -1 to 0
// so that changed 0's dont interfare while traversal
// void mark_row(std::vector<std::vector<int>> &vec, int i, int m){
//       for(int j = 0; j < m; j++){
//             if(vec[i][j] != 0){
//                   vec[i][j] = -1;
//             }
//       }
// }
// void mark_column(std::vector<std::vector<int>> &vec, int j, int n){
//       for(int i = 0; i < n; i++){
//             if(vec[i][j] != 0){
//                   vec[i][j] = -1;
//             }
//       }
// }
// void set_zeroes(std::vector<std::vector<int>> &matrix){
//       int n = matrix.size();
//       int m = matrix[0].size();
//       for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                   if(matrix[i][j] == 0){
//                         mark_row(matrix, i, m);
//                         mark_column(matrix, j, n);
//                   }
//             }
//       }
//       for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                   if(matrix[i][j] == -1){
//                         matrix[i][j] = 0;
//                   }
//             }
//       }
// }

// BETTER
// void set_zeroes(std::vector<std::vector<int>> &matrix){
      // int n = matrix.size();
      // int m = matrix[0].size();
//       std::vector<int> row(n, 0);
//       std::vector<int> col(m, 0);
//       for(int i = 0; i< n; i++){
//             for(int j = 0; j < m; j++){
//                   if(matrix[i][j] == 0){
//                         row[i] = 1;
//                         col[j] = 1;
//                   }
//             }
//       }
//       for(int i = 0; i< n; i++){
//             for(int j = 0; j < m; j++){
//                   if(row[i] || col[j]){
//                         matrix[i][j] = 0;
//                   }
//             }
//       }
// }

// OPTIMAL
void set_zeroes(std::vector<std::vector<int>> &matrix){
      int n = matrix.size();
      int m = matrix[0].size();
      int col0 = 1;
      for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                  if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        if(j != 0){
                              matrix[0][j] = 0;
                        }
                        else{
                              col0 = 0;
                        }
                  }
            }
      }
      for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                  if(matrix[i][j] != 0){
                        if(matrix[0][j] == 0 || matrix[i][0] == 0){
                              matrix[i][j] = 0;
                        }
                  }
            }
      }
      if(matrix[0][0] == 0){
            for(int j = 0; j < m; j++){
                  matrix[0][j] = 0;
            }
      }
      if(col0 = 0){
            for(int i = 0; i < n; i++){
                  matrix[i][0] = 0;
            }
      }
}

int main(){
      int row, column;
      std::cout << "Enter the number of rows: ";
      std::cin >> row;
      std::cout << "Enter the number of columns: ";
      std::cin >> column;
      std::vector<std::vector<int>> matrix(row, std::vector<int>(column));

      for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                  std::cin >> matrix[i][j];
            }
      }

      set_zeroes(matrix);

      for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                  std::cout << matrix[i][j] << "\t";
            }
            std::cout << "\n";
      }
      return 0;
}