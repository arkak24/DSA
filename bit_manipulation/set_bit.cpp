#include <iostream>

int main(){
      int n;
      std::cout << "Enter a number : ";
      std::cin >> n;

      int i;
      std::cout << "Enter the bit number to set : ";
      std::cin >> i;

      int temp = 1 << i;
      
      temp = n | temp;

      std::cout << temp << std::endl;
      return 0;
}
