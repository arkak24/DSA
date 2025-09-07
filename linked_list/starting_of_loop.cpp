#include "singly_structure.hpp"

#include <map>

// BRUTE
// TC : O(2*n*log(n)); SC : O(n)
// Node* starting_loop(Node* head){
//       std::map<Node*, int> mpp;
//       Node* temp = head;
//       while(temp != nullptr){
//             if(mpp.find(temp) != mpp.end()){
//                   return temp;
//             }
//             mpp[temp] = 1;
//             temp = temp -> next;
//       }
//       return nullptr;
// }

// BETTER
// Tortoise hare
// TC : O(n); SC : O(1)
Node* starting_loop(Node* head){
      Node* fast = head;
      Node* slow = head;
      while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                  slow = head;
                  while(slow != fast){
                        slow = slow -> next;
                        fast = fast -> next;
                  }
                  return slow;
            }
      }
      return nullptr;
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

      std::cout << starting_loop(head) << std::endl;

      free_List(head);

      return 0;
}