#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
      public:
            void reverseWords(string s) {

                  int n = s.size();

                  vector<string> temp;
                  int vect_counter = 0;

                  int it = 0;

                  while(it < s.size()){
                        string str;
                        while(s[it] != ' '){
                              str += s[it];
                              it++;
                        }
                        temp.push_back(str);
                        if(s[it] != ' '){
                              vect_counter++;
                        }
                  }

                  for(int i = 0; i < temp.size(); i++){
                        cout << temp[i] << " ";
                  }

                  cout << "\n";

                  // return str;
            }
};

int main(){
      string str;
      cout << "Enter the string : ";
      getline(cin, str);

      Solution revstr;

      // string ans = revstr.reverseWords(str);

      // cout << ans << endl;

      return 0;
}
