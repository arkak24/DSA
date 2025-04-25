#include <bits/stdc++.h>

using namespace std;

// BRUTE 
// TC : O(n); SC : O(n)

// this one rotates the array on the left side

// void rotate_d(vector<int> &vect, int no_of_places){
//       vector<int> temp = vect;
//       no_of_places = no_of_places % vect.size();

//       // shift the leftover array
//       for(int i = no_of_places; i < vect.size(); i++){
//             vect[i-no_of_places] = vect[i];
//       }

//       // put the first elements stored in the temp in the last of the array
//       for(int i = 0; i < no_of_places; i++){
//             vect[vect.size() - no_of_places + i] = temp[i];
//       }
// }

/* ------------------------------------------------------------------------------------ */

// OPTIMAL
// TC : O(2n); SC : O(1)

// this one rotate the array to the right side

// to rotate left first rotate the sub portions and the rotate the whole thing
// to rotate right first rotate the whole and then rotate the sub portions

void rotate_d(vector<int> &nums, int k) {
      int sizev = nums.size();
      k %= sizev;
      reverse(nums.begin(),nums.begin()+sizev);
      reverse(nums.begin(),nums.begin()+k);
      reverse(nums.begin()+k,nums.begin()+sizev);
}

int main(){
      vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
      int places = 3;
      rotate_d(vec, places);
      
      for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << "\t";
      }

      return 0;
}