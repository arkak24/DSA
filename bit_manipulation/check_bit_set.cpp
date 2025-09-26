#include <iostream>

int main(){
      int n = 13;
      int i = 2;

      // we do left shift if 1 to the i'th terms then do AND
      // if the ans = 0 -> not set
      // else set

      int ans = 1;
      ans = ans << i;
      ans = n & ans;

      if(ans == 0) std::cout << "not set" << std::endl;
      else std::cout << "set" << std::endl;
      
      // we can also use the right shift operator to the 'n' itself
      // then do AND with 1
      // if ans = 0 -> not set
      // else set

      return 0;
}
