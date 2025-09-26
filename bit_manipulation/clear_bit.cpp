#include <iostream>

int main(){
      int n = 13;
      int i = 2;

      int temp = 1 << i;
      temp = ~temp;

      temp = temp & n;
      std::cout << temp << std::endl;
      return 0;
}
