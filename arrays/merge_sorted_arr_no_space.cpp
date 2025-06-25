#include <iostream>
#include <vector>
#include <algorithm>

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

// OPTIMAL 1
// 2 pointer approach, taking advantage of the fact that the array are sorted
// TC : O(min(n, m))+O(n.logn)+O(m.logm); SC : O(1)
// void merge(std::vector<int> &nums1, std::vector<int> &nums2, int n, int m){
//       int left = n - 1;
//       int right = 0;
//       while(left >= 0 && right < m){
//             if(nums1[left] > nums2[right]){
//                   std::swap(nums1[left], nums2[right]);
//                   left--;
//                   right++;
//             }
//             else{
//                   break;
//             }
//       }
//       std::sort(nums1.begin(), nums1.end());
//       std::sort(nums2.begin(), nums2.end());
// }

// OPTIMAL 2
// gap method, using shell sort
void swap_element(std::vector<int> &nums1, std::vector<int> &nums2, int idx1, int idx2){
      if(nums1[idx1] > nums2[idx2]){
            std::swap(nums1[idx1], nums2[idx2]);
      }
}
void merge(std::vector<int> &nums1, std::vector<int> &nums2, int n, int m){
      int len = n+m;
      int gap = (len/2) + (len%2);
      while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                  if(left < n && right >= n){
                        swap_element(nums1, nums2, left, right-n);
                  }
                  else if(left >= n){
                        swap_element(nums2, nums2, left-n, right-n);
                  }
                  else{
                        swap_element(nums1, nums1, left, right);
                  }
                  left++;
                  right++;
            }
            if(gap == 1) break;
            gap = (gap/2) + (gap%2);
      }
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