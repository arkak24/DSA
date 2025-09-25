#include <iostream>

// TC : O(2*n), accurately O($*n) where $ is the golden ratio -> 1.618
int fib_seq(int n){
      if(n <= 1) return n;
      int last = fib_seq(n-1);      // this whole will be executed first
      int sec_last = fib_seq(n-2);  // then this
      return last+sec_last;
}

int main(){
      int n = 5;
      int ans = fib_seq(n);
      std::cout << ans << std::endl;
      return 0;
}