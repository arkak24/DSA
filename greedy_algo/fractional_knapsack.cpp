#include <iostream>
#include <vector>
#include <algorithm>

struct Item{
      int value;
      int weight;

      static bool cmp(const Item &val1, const Item &val2){  // 'static': we can use it from anywhere in the code
            if(double(val1.value)/val1.weight > double(val2.value)/val2.weight){
                  return true;
            }
            else return false;
      }
};
// as we used 'static' so the 'cmp' function belongs to the class itself
// and will not be tied to any object
// to access the function we have to use '::' like 'Item::cmp'

double func(std::vector<Item> &vec, int W){
      std::sort(vec.begin(), vec.end(), Item::cmp);
      float total_val = 0;
      for(int i = 0; i < vec.size(); i++){
            if(vec[i].weight <= W){
                  total_val += vec[i].value;
                  W -= vec[i].weight;
            }
            else{
                  total_val += (float(vec[i].value)/vec[i].weight) * W;
                  break;
            }
      }
      return total_val;
}

int main(){
      std::vector<Item> vec = {
            {100, 20},
            {60, 10},
            {100, 50},
            {200, 50}
      };
      // because we have the struct like: struct Item{...}
      // so we will have to use the '{}' while declaring

      float ans = func(vec, 90);
      std::cout << "ans: " << ans << std::endl;

      return 0;
}
