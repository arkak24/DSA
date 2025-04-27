//BRUTE -> linear search
// #include<iostream>
// using namespace std;
// int main(){

//}

//BETTER -> hashing
// #include<iostream>
// using namespace std;

// int main(){
//     int arr[] = {1,2,4,5};
//     int n = 5;
//     int hash[6] = {0};
//     for(int i=0;i<n;i++){
//         hash[arr[i]] = 1;
//     }
//     for(int i=1;i<n;i++){
//         if(hash[i] == 0){
//             cout << i;
//         }
//     }
//     return 0;
// }

//OPTIMAL
#include<iostream>
using namespace std;

int main(){
      int arr[] = {1,2,4,5};
      int n = 5;
      int temp = n*(n+1)/2;
      int sum = 0;
      for(int i=0;i<4;i++){   //O(n-1)
            sum = sum + arr[i];
      }
      cout << "The missing number is " << (temp-sum);
      return 0;
}