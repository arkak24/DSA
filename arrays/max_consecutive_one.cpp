#include <iostream>
#include <vector>

// OPTIMAL
// TC : O(n); SC : O(1)
int count_max_one(std::vector<int> vec){
      int count = 0;
      int maximum = 0;

      for(int i = 0; i < vec.size(); i++){
            if(vec[i] == 1){
                  count++;
            }
            if(vec[i] == 0){
                  count = 0;
            }
            maximum = std::max(maximum, count);
      }
      return maximum;
}

int main(){
      std::vector<int> vect;
      vect = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1};

      int ans = count_max_one(vect);
      std::cout << "Max consecutive one's = " << ans;
      return 0;
}