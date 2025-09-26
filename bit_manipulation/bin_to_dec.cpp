#include <iostream>
#include <string>

// TC : O(len); SC : O(1)
int binary2decimal(std::string str){
      int len = str.length();

      if(len == 0) return 0;

      int power_2 = 1;
      int ans = 0;
      for(int i = len-1; i >= 0; i--){
            if(str[i] == '1'){
                  ans = ans + power_2;
            }
            power_2 = power_2 * 2;
      }
      return ans;
}

int main(){
      std::string str;
      std::cout << "Enter a binary string : ";
      std::cin >> str;
      std::cout << binary2decimal(str) << std::endl;
      return 0;
}