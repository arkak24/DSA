#include <iostream>
#include <string>

// int count_bits(int n){
//       int count = 0;
//       while(n != 0){
//             count += n & 1;
//             n = n >> 1;
//       }
//       if(n == 1) count += 1;
//       return count;
// }

int count_bits(int n){
      int count = 0;
      while(n != 0){
            n = n & (n-1);
            count += 1;
      }
      return count;
}

int main(){
      int n;
      std::cout << "Enter the number : ";
      std::cin >> n;
      std::cout << count_bits(n) << std::endl;
      return 0;
}
