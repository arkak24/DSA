//BRUTE
//(TC -> O(n^2))(SC -> O(1))
// #include<iostream>
// using namespace std;
// int main(){
//       int arr[] = {1,1,2,3,3,4,4};
//       int n = sizeof(arr)/sizeof(arr[0]);
//       for(int i=0;i<n;i++){
//             int num = arr[i];
//             int count = 0;
//             for(int j=0;j<n;j++){
//                   if(arr[j] == num){
//                   count++;
//                   }
//             }
//             if(count == 1) cout << num;
//       }
//       return 0;
// }

//BETTER -> HASHING(cannot be used if negative number and large numbers are present)
//(TC -> O(3*n))(SC -> O(max+1))
// #include<iostream>
// using namespace std;
// int main(){
//       int arr[] = {1,1,2,3,3,4,4};
//       int n = sizeof(arr)/sizeof(arr[0]);
//       int max = arr[0];
//       for(int i=0;i<n;i++){
//             if(arr[i] > max){
//                   max = arr[i];
//             }
//       }
//       int hash[max+1] = {0};
//       for(int i=0;i<n;i++){
//             hash[arr[i]] = hash[arr[i]]+1;
//       }
//       for(int i=1;i<=max;i++){
//             if(hash[i] == 1){
//                   cout << i;
//             }
//       }
//       return 0;
// }

//OPTIMAL -> use xor throughout the array
#include<iostream>
using namespace std;
int main(){
      int arr[] = {1,1,2,3,3,4,4};
      int n = sizeof(arr)/sizeof(arr[0]);
      int ans = 0;
      for(int i = 0; i < n; i++){
            ans = ans^arr[i];
      }
      cout << ans;
      return 0;
}