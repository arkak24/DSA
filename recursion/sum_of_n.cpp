#include <iostream>

// paramerterizesd
// void sum_of_n(int i, int ans){
//       if(i < 1){
//             std::cout << "The sum is : " << ans << std::endl;
//             return;
//       }
//       sum_of_n(i-1, ans+i);
// }
// int main(){
//       int n;
//       std::cout << "Enter the number : ";
//       std::cin >> n;
//       sum_of_n(n, 0);
//       return 0;
// }

/*----------------------------------------------*/

// functional
int sum_of_n(int n){
      if(n == 0) return 0; 
      return n+sum_of_n(n-1);
}
int main(){
      int n;
      std::cout << "Enter the number : ";
      std::cin >> n;
      int ans = sum_of_n(n);
      std::cout << "Ans : " << ans << std::endl;
      return 0;
}