#include <iostream>

// int count = 0;
// void print_func(){
//       if(count == 3) return;        // base condition
//       std::cout << count << std::endl;
//       count++;
//       print_func();
// }
// int main(){
//       print_func();
//       return 0;
// }

/*---------------------------------------------------------------------------*/

// print name n times
// void print_name(int i, int n){
//       if(i > n) return;
//       std::cout << "name" << std::endl;
//       print_name(i+1, n);
// }
// int main(){
//       int n;
//       std::cout << "Enter a number : ";
//       std::cin >> n;
//       print_name(1, n);
//       return 0;
// }

/*---------------------------------------------------------------------------*/

// print linearly from 1 to n
// int n = 1;
// void print_nums(){
//       if(n == 6) return;
//       std::cout << n << std::endl;
//       n++;
//       print_nums();
// }
// int main(){
//       print_nums();
//       return 0;
// }

/*---------------------------------------------------------------------------*/

// print linearly from 1 to n
// void print_num(int i, int n){
//       if(i > n) return;
//       std::cout << i << std::endl;
//       print_num(i+1, n);
// }
// int main(){
//       int n;
//       std::cout << "Enter the number : ";
//       std::cin >> n;
//       print_num(1, n);
// }

/*---------------------------------------------------------------------------*/

// print linearly from 1 to n (backtrack)
// void print_num(int i){
//       if(i < 1) return;
//       print_num(i-1);
//       std::cout << i << std::endl;
// }
// int main(){
//       int n;
//       std::cout << "Enter the number : ";
//       std::cin >> n;
//       print_num(n);
//       return 0;
// }

/*---------------------------------------------------------------------------*/

// print n to 1
// void print_num(int i){
//       if(i < 1) return;
//       std::cout << i << std::endl;
//       print_num(i-1);
// }
// int main(){
//       int n;
//       std::cout << "Enter the number : ";
//       std::cin >> n;
//       print_num(n);
//       return 0;
// }

/*---------------------------------------------------------------------------*/

// print n to 1 (backtracking)
void print_num(int i, int n){
      if(i > n) return;
      print_num(i+1, n);
      std::cout << i << std::endl;
}
int main(){
      int n;
      std::cout << "Enter the number : ";
      std::cin >> n;
      print_num(1, n);
      return 0;
}