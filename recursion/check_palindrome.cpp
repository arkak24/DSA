#include <iostream>
#include <string>

bool check_palindrome(std::string &str, int i){
      if(i >= str.size()/2) return true;
      if(str[i] != str[str.size()-i-1]) return false;
      return check_palindrome(str, i+1);
}

int main(){
      std::string str = "madam";
      bool ans = check_palindrome(str, 0);
      std::cout << ans << std::endl;
      return 0;
}