#include <iostream>

int main(){
      int a = 5;
      int b = 6;

      // swapping
      a = a ^ b;
      b = a ^ b;        // (a ^ b) ^ b = a
      a = a ^ b;        // (a ^ b) ^ a = b

      std::cout << "a = " << a << ", b = " << b << std::endl;
      return 0;
}
