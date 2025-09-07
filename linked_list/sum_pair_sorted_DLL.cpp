// have to find the pair from a sorted DLL

#include "doubly_structure.hpp"

#include <utility>

// TC : approx O(n^2); SC : O(1)
// std::vector<std::pair<int, int>> finding_pair(Node* head, int sum){
//       Node* temp1 = head;
//       std::vector<std::pair<int, int>> ans;
//       while(temp1 != nullptr){
//             Node* temp2 = temp1 -> next;
//             while(temp2 != nullptr && (temp1 -> data + temp2 -> data <= sum)){
//                   if(temp1 -> data + temp2 -> data == sum){
//                         ans.push_back({temp1 -> data, temp2 -> data});
//                   }
//                   temp2 = temp2 -> next;
//             }
//             temp1 = temp1 -> next;
//       }
// }

// TC : O(2*n); SC : O(1)
Node* find_tail(Node* head){
      Node* temp = head;
      while(temp -> next != nullptr){
            temp = temp -> next;
      }
      return temp;
}
std::vector<std::pair<int, int>> finding_pair(Node* head, int sum){
      std::vector<std::pair<int, int>> ans;
      if(head == nullptr){
            return ans;
      }
      Node* left = head;
      Node* right = find_tail(head);
      while(left -> data < right -> data){
            if(left -> data + right -> data == sum){
                  ans.push_back({left -> data, right -> data});
                  left = left -> next;
                  right = right -> next;
            }
            else if(left -> data + right -> data < sum){
                  left = left -> next;
            }
            else{
                  right = right -> next;
            }
      }
      return ans;
}

int main(){
      std::vector<int> vec = {1, 2, 3, 4, 5};
      Node* head = convertArr2DLL(vec);
      
      std::vector<std::pair<int, int>> ans = finding_pair(head, 5);

      free_DLL(head);

      return 0;
}