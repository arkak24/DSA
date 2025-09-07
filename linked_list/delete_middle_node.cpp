#include "singly_structure.hpp"

// BRUTE
// TC : O(n+n/2); SC : O(1)
// Node* delete_middle_element(Node* head) {
//       if (head == nullptr) return nullptr;

//       Node* temp = head;
//       int count = 0;

//       while (temp != nullptr) {
//             count++;
//             temp = temp->next;
//       }
//       int mid = count / 2;
//       temp = head;
//       while (temp != nullptr) {
//             mid--;
//             if(mid == 0){
//                   Node* temp_mem = temp -> next;
//                   temp -> next = temp -> next -> next;
//                   delete temp_mem;
//                   break;
//             }
//             temp = temp -> next;
//       }
//       return head;
// }


// OPTIMAL
// TC : O(n/2); SC : O(1)
Node* delete_middle_element(Node* head) {
      if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
      }
      Node* slow = head;
      Node* fast = head;
      Node* prev = nullptr;

      while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
      }
      // slow is standing at the second middle incase of even after this loop
      // so we are deelting second middle incase of even number of elements
      prev->next = slow->next;
      delete slow;
      return head;  
}

int main(){
      std::vector<int> vec = {1, 2, 3, 4, 5};
      Node* head = convertArr2LL(vec);

      print_list(head);

      head = delete_middle_element(head);

      print_list(head);
      free_List(head);
      
      return 0;
}