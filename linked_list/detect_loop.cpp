#include "singly_structure.hpp"

#include <map>

// BRUTE
// TC : O(n*log(n)); SC : O(n)
// bool detect_loop(Node* head){
//       std::map<Node*, int> mpp;
//       Node* temp = head;
//       while(temp != nullptr){
//             if(mpp[temp] == 1){
//                   return true;
//             }
//             mpp[temp]++;
//             temp = temp -> next;
//       }
//       return false;
// }

// BETTER
// Floyd's cycle detection / Tortoise hare
// TC : O(n); SC : O(1)
bool detect_loop(Node* head){
      Node* fast = head;
      Node* slow = head;
      while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
      }
      return false;
}

int main(){
      std::vector<int> vec = {1, 2, 3, 4, 5};
      Node* head = convertArr2LL(vec);

      Node* temp_mem = head -> next -> next;

      Node* temp = head;
      while(temp -> next != nullptr){
            temp = temp -> next;
      }
      temp -> next = temp_mem;

      std::cout << detect_loop(head) << std::endl;

      free_List(head);

      return 0;
}