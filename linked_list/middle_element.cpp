#include "singly_structure.hpp"

// BRUTE
// TC : O(n+n/2); SC : O(1)
// Node* middle_element(Node* head){
//       Node* temp = head;
//       int count = 0;
//       while(temp != nullptr){
//             count++;
//             temp = temp -> next;
//       }
//       int mid = (count/2) + 1;
//       temp = head;
//       while(temp != nullptr){
//             mid--;
//             if(mid == 0) break;
//             temp = temp -> next;
//       }
//       return temp;
// }

// OPTIMAL
// TC : O(n/2); SC : O(1)
Node* middle_element(Node* head){
      Node* fast = head;
      Node* slow = head;
      while(fast -> next != nullptr && fast -> next -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
      }
      if(fast -> next == nullptr) return slow;
      return slow -> next;
}

int main(){
      std::vector<int> vec = {1, 2, 3, 4, 5};
      Node* head = convertArr2LL(vec);

      Node* ans = middle_element(head);
      std::cout << ans -> data << std::endl;

      free_List(head);
      
      return 0;
}