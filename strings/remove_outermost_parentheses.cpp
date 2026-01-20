#include <iostream>
#include <string>

int main(){
      std::string str;
      std::cout << "Enter the string: ";
      std::cin >> str;

      int balance = 0;
      int start_idx = 0;

      for(int i = 0; i < str.size(); i++){
            if(str[i] == '('){
                  if(balance == 0){
                        start_idx = i;
                  } 
                  balance++;
            }
            else if(str[i] == ')'){
                  balance--;
                  if(balance == 0){
                        for(int j = start_idx+1; j < i; j++){
                              std::cout << str[j];
                        }
                  }
            }
      }
      std::cout << "\n";

      return 0;
}
