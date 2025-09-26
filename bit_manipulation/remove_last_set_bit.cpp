#include <iostream>

int main(){
      int n = 16;
      int ans = n & (n-1);
      std::cout << ans << std::endl;
      return 0;
}
