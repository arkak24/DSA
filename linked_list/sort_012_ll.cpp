#include "singly_structure.hpp"

// BRUTE (data replacement)
// TC : O(2n); SC : O(1)
// Node* sort012(Node* head){
//       Node* temp = head;
//       int count0 = 0, count1 = 0, count2 = 0;
//       while(temp != nullptr){
//             if(temp -> data == 0) count0++;
//             else if(temp -> data == 1) count1++;
//             else count2++;
//             temp = temp -> next;
//       }
//       temp = head;
//       while(temp != nullptr){
//             if(count0 != 0){
//                   temp -> data = 0;
//                   count0--;
//             }
//             else if(count1 != 0){
//                   temp -> data = 1;
//                   count1--;
//             }
//             else{
//                   temp -> data = 2;
//                   count2--;
//             }
//             temp = temp -> next;
//       }
//       return head;
// }

// BETTER (changing the links)
Node* sort012(Node* head){
      Node* head_0 = nullptr;
      Node* head_1 = nullptr;
      Node* head_2 = nullptr;

      Node* prev_0 = nullptr;
      Node* prev_1 = nullptr;
      Node* prev_2 = nullptr;
      
      Node* temp = head;
      while(temp != nullptr){
            if(temp -> data == 0){
                  if(head_0 == nullptr) head_0 = temp;
                  else prev_0 -> next = temp;
                  prev_0 = temp;
            }
            else if(temp -> data == 1){
                  if(head_1 == nullptr) head_1 = temp;
                  else prev_1 -> next = temp;
                  prev_1 = temp;
            }
            else{
                  if(head_2 == nullptr) head_2 = temp;
                  else prev_2 -> next = temp;
                  prev_2 = temp;
            }
            temp = temp -> next;
      }
      
      if(prev_0 != nullptr) prev_0 -> next = nullptr;
      if(prev_1 != nullptr) prev_1 -> next = nullptr;
      if(prev_2 != nullptr) prev_2 -> next = nullptr;

      Node* new_head = nullptr;
      if(head_0 != nullptr){
            new_head = head_0;
            if(head_1 != nullptr){
                  prev_0 -> next = head_1;
                  if(head_2 != nullptr){
                        prev_1 -> next = head_2;
                  }
            }
            else if(head_2 != nullptr){
                  prev_0 -> next = head_2;
            }
      }
      else if(head_1 != nullptr){
            new_head = head_1;
            if(head_2 != nullptr){
                  prev_1 -> next = head_2;
            }
      }
      else{
            new_head = head_2;
      }

      return new_head;
}

int main(){
      std::vector<int> vect = {2, 0, 2, 0, 0};

      Node* head = convertArr2LL(vect);

      head = sort012(head);

      print_list(head);
      free_List(head);

      return 0;
}