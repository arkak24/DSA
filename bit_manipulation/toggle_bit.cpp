#include <iostream>

int main(){
      int n = 13;
      int i = 2;

      int ans = 1 << i;
      ans = n ^ ans;
      std::cout << ans << std::endl;
      return 0;
}
