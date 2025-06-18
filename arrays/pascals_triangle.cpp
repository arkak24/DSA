#include <iostream>
#include <vector>

// BRUTE to print any element from given row and column number
// int factorial(int n){
//       int res = 1;
//       for(int i = 1; i <= n; i++){
//             res = res*i;
//       }
//       return res;
// }
// int main(){
//       int row, column;
//       std::cout << "Enter the number of rows : ";
//       std::cin >> row;
//       std::cout << "Enter the number of columns : ";
//       std::cin >> column;
//       int ans = factorial(row-1)/(factorial(column-1)*factorial(row-column));
//       std::cout << row << "C" << column << " = " << ans << std::endl;
//       return 0;
// }

/* --------------------------------------------------------------------------------------------- */

// OPTIMAL to print any element from given row and column number
// int nCr(int n, int r){
//       int res = 1;
//       for(int i = 0; i < r; i++){
//             res = res*(n-i);
//             res = res/(i+1);
//       }
//       return res;
// }
// int main(){
//       int row, column;
//       std::cout << "Enter the number of rows : ";
//       std::cin >> row;
//       std::cout << "Enter the number of columns : ";
//       std::cin >> column;
//       int ans = nCr(row-1, column-1);
//       std::cout << row << "C" << column << " = " << ans << std::endl;
//       return 0;
// }

/* --------------------------------------------------------------------------------------------- */

// BRUTE to print any row of the pascal triangle
// int nCr(int n, int r){
//       int res = 1;
//       for(int i = 0; i < r; i++){
//             res = res*(n-i);
//             res = res/(i+1);
//       }
//       return res;
// }
// void pascal_row(int n){
//       for(int i = 0; i <= n; i++){
//             std::cout << nCr(n, i) << "\t";
//       }
// }
// int main(){
//       int row, column;
//       std::cout << "Enter the row number : ";
//       std::cin >> row;
//       pascal_row(row-1);
//       std::cout << "\n";
//       return 0;
// }

/* --------------------------------------------------------------------------------------------- */

// OPTIMAL to print any row of the pascal triangle
// void pascal_row(int n){
//       int temp = 1;
//       std::cout << temp << "\t";
//       for(int i = 1; i <= n; i++){
//             temp = temp * (n-i+1);
//             temp = temp / i;
//             std::cout << temp << "\t";
//       }
// }
// int main(){
//       int row, column;
//       std::cout << "Enter the row number : ";
//       std::cin >> row;
//       pascal_row(row-1);
//       std::cout << "\n";
//       return 0;
// }

/* --------------------------------------------------------------------------------------------- */

// BRUTE to print the whole pascals triangle
// is to run nested for loop and use the function to create any element from the row and column number

/* --------------------------------------------------------------------------------------------- */

// OPTIMAL to print the whole pascals triangle
std::vector<int> pascal_row(int row){
      long long ans = 1;
      std::vector<int> ansRow;
      ansRow.emplace_back(1);
      for(int col = 1; col < row; col++){
            ans = ans * (row-col);
            ans = ans / col;
            ansRow.emplace_back(ans);
      }
      return ansRow;
}

void pascal_triangle(int n){
      std::vector<std::vector<int>> ans;
      for(int i = 1; i <= n; i++){
            ans.emplace_back(pascal_row(i));
      }
      for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                  std::cout << ans[i][j] << "\t";
            }
            std::cout << "\n";
      }
}

int main(){
      int row, column;
      std::cout << "Enter the row number : ";
      std::cin >> row;
      pascal_triangle(row);
      std::cout << "\n";
      return 0;
}