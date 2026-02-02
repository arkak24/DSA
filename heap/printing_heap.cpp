#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main(){
      std::vector<int> arr = {2, 3, 5, 1, 6, 4, 9};
      std::make_heap(arr.begin(), arr.end());   // only way to see the internal structure
                                                // after every pop in the heap, it readjusts itself
                                                // hence we get the sorted order
      for(int x: arr) std::cout << x << " ";

      // std::priority_queue<int, std::vector<int>, std::greater<int>> minh;
      //
      // for(int x : arr) minh.push(x);
      // int size = minh.size();
      // for(int i = 0; i < size; i++){
      //       std::cout << minh.top() << " ";
      //       minh.pop();
      // }

      std::cout << "\n";

      return 0;
}
