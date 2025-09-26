#include <iostream>
#include <string>
#include <algorithm>

// TC : O(logn); SC : O(logn)
std::string convert2bin(int n){
      std::string result = "";
      while(n > 0){
            if(n%2 == 1) result+='1';
            else result+='0';
            n = n/2;
      }
      std::reverse(result.begin(), result.end());
      return result;
}
int main(){
      int n;
      std::cout << "Enter the decimal number : ";
      std::cin >> n;
      std::cout << convert2bin(n) << std::endl;
      return 0;
}