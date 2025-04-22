// TC -> O(n)

#include <bits/stdc++.h>
using namespace std;

int is_sorted(vector<int> vect){
      for(int i = 1; i < vect.size(); i++){
            if(vect[i] >= vect[i-1]){

            }
            else{
                  return 0;
            }
      }
      return 1;
}

int main(){
      vector<int> vec = {1, 2, 4, 7, 7, 9};
      int ans = is_sorted(vec);
      cout << ans;
      return 0;
}