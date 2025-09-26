// the number is a power of 2 then there will be only one bit set
// in the whole binary number

#include <iostream>

int main(){
      int n = 16;
      int ans = n & (n-1);
      if(ans == 0) std::cout << "It is power of 2" << std::endl;
      else std::cout << "not power of 2" << std::endl;
      return 0;
}
