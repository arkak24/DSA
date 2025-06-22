#include <iostream>
#include <vector>

// BRUTE
// merge sorted and then divide
// TC : 2*O(n+m); SC : O(n+m)
// void merge(std::vector<int> &nums1, std::vector<int> &nums2, int n, int m){
//       std::vector<int> nums3(m+n);
//       int left = 0;
//       int right = 0;
//       int index = 0;
//       while(left < n && right < m){
//             if(nums1[left] <= nums2[right]){
//                   nums3[index] = nums1[left];
//                   index++;
//                   left++;
//             }
//             else{
//                   nums3[index] = nums2[right];
//                   index++;
//                   right++;
//             }
//       }
//       while(left < n){
//             nums3[index] = nums1[left];
//             index++;
//             left++;
//       }
//       while(right < m){
//             nums3[index] = nums2[right];
//             index++;
//             right++;
//       }
//       for(int i = 0; i < n+m; i++){
//             if(i < n){
//                   nums1[i] = nums3[i];
//             }
//             else{
//                   nums2[i-n] = nums3[i];
//             }
//       }
// }

// OPTIMAL
void merge(std::vector<int> &nums1, std::vector<int> &nums2, int n, int m){

}

int main(){
      int n, m;
      std::cout << "Enter the number of elements of the first array : ";
      std::cin >> n;
      std::cout << "Enter the number of elements of the second array : ";
      std::cin >> m;
      std::vector<int> nums1(n);                                  
      std::vector<int> nums2(m);
      std::cout << "Enter the elements of the forst array : ";
      for(int i = 0; i < n; i++){
            std::cin >> nums1[i];
      }
      std::cout << "Enter the elements of the second array : ";
      for(int i = 0; i < m; i++){
            std::cin >> nums2[i];
      }
      merge(nums1, nums2, n, m);

      std::cout << "First array : ";
      for(int i = 0; i < n; i++){
            std::cout << nums1[i] << "\t";
      }
      std::cout << "\n";
      std::cout << "Second array : ";
      for(int i = 0; i < m; i++){
            std::cout << nums2[i] << "\t";
      }
      std::cout << "\n";

      return 0;
}