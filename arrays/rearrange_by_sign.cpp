// array consisting equal number of positives and negatives will be given
// have to rearrange the array like + - + - alternating
// without hampering the initial sequence of the positives and the negatives

#include <iostream>
#include <vector>

// BRUTE
// seperate the positive and negatives and then put in the original array
// TC : O(2n); SC : O(n)
// void rearrange_by_sign(std::vector<int> &vect){
//       std::vector<int> positives;
//       std::vector<int> negatives;

//       for(int i = 0; i < vect.size(); i++){
//             if(vect[i] >= 0){
//                   positives.emplace_back(vect[i]);
//             }
//             else{
//                   negatives.emplace_back(vect[i]);
//             }
//       }

//       for(int i = 0; i < vect.size()/2; i++){
//             vect[2*i] = positives[i];
//             vect[2*i + 1] = negatives[i];
//       }
// }

// OPTIMAL
// but here we are not doing the changes in the original array
// two pointer approach
// TC : O(n); SC : O(n)
// std::vector<int> rearrange_by_sign(std::vector<int> &vect){
//       std::vector<int> ans(vect.size());
//       int i = 0;
//       int j = 1;
//       for(int k = 0; k < vect.size(); k++){
//             if(vect[k] >=0){
//                   ans[i] = vect[k];
//                   i+=2;
//             }
//             else{
//                   ans[j] = vect[k];
//                   j+=2;
//             }
//       }
//       return ans;
// }

// what is the number of positive ans negatives are not equal
// then we cant use the optimal approach
// have to use the brute solution
void rearrange_by_sign(std::vector<int> &vect){
      std::vector<int> pos;
      std::vector<int> neg;

      for(int i = 0; i < vect.size(); i++){
            if(vect[i] >= 0){
                  pos.emplace_back(vect[i]);
            }
            else{
                  neg.emplace_back(vect[i]);
            }
      }

      if(pos.size() > neg.size()){
            for(int i = 0; i < neg.size(); i++){
                  vect[2*i] = pos[i];
                  vect[2*i + 1] = neg[i];
            }
            int idx = 2*neg.size();
            for(int i = neg.size(); i < pos.size(); i++){
                  vect[idx] = pos[i];
                  idx++;
            }
      }
      else{
            for(int i = 0; i < pos.size(); i++){
                  vect[2*i] = pos[i];
                  vect[2*i + 1] = neg[i];
            }
            int idx = 2*pos.size();
            for(int i = pos.size(); i < neg.size(); i++){
                  vect[idx] = neg[i];
                  idx++;
            }
      }
}


int main(){
      std::vector<int> vect = {-3, 1, 2, -5, 2, -4, 5, 6, 7, -10};

      rearrange_by_sign(vect);

      for(int i = 0; i < vect.size(); i++){
            std::cout << vect[i] << "\t";
      }
      std::cout << "\n";

      return 0;
}