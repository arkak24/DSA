#include <iostream>
#include <vector>

void swap(int &a, int &b){
      int c = a;
      a = b;
      b = c;
}
// void rev_arr(std::vector<int> &a, int l, int r){
//       if(l >= r) return;
//       swap(a[l], a[r]);
//       rev_arr(a, l+1, r-1);
// }
void rev_arr(std::vector<int> &a, int i){
      if(i >= a.size()/2) return;
      swap(a[i], a[a.size()-i-1]);
      rev_arr(a, i+1);
}
int main(){
      std::vector<int> a = {1, 2, 3, 4, 5};
      rev_arr(a, 0);
      for(int i = 0; i < a.size(); i++){
            std::cout << a[i] << "\t";
      }
      std::cout << std::endl;
      return 0;
}