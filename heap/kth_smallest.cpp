#include <iostream>
#include <vector>
#include <queue>

int kth(std::vector<int>& arr, int k){
      std::priority_queue<int, std::vector<int>, std::less<int>> maxh;

      for(int i = 0; i < arr.size(); i++){
            maxh.push(arr[i]);

            if(maxh.size() > k){
                  maxh.pop();
            }
      }
      return maxh.top();
}

int main(){
      std::vector<int> vec = {7, 10, 4, 3, 20, 15};

      int ans = kth(vec, 3);
      std::cout << ans << std::endl;

      return 0;
}
