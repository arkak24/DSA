#include "singly_structure.hpp"

#include <map>

// BRUTE
// TC : O(n*log(n)); SC : O(n)
// int loop_length(Node* head){
//       std::map<Node*, int> mpp;
//       Node* temp = head;
//       int count = 0;
//       while(temp != nullptr){
//             if(mpp.find(temp) != mpp.end()){
//                   int val = count - mpp[temp];     // because 0 based counting
//                   return val;
//             }
//             mpp[temp] = count;
//             count++;
//             temp = temp -> next;
//       }
//       if(temp == nullptr) return 0;
// }
// both same, see the difference
// if count initialized as 0 and not 1 then using:
// if (mpp[temp] != 0) return (count - mpp[temp]);
// will not work as map by default sets val as 0
// there will be collision for the first node
// int loop_length(Node* head) {
//     std::map<Node*, int> mpp;
//     Node* temp = head;
//     int count = 1;

//     while (temp != nullptr) {
//         if (mpp[temp] != 0) {
//             return count - mpp[temp];
//         }
//         mpp[temp] = count;
//         count++;
//         temp = temp->next;
//     }
//     return 0; // no cycle
// }


// BETTER
// Floyd's cycle detection / Tortoise hare
// TC : O(n); SC : O(1)
int find_length(Node* slow, Node* fast){
      int count = 1;
      fast = fast -> next;
      while(slow != fast){
            count++;
            fast = fast -> next;
      }
      return count;
}
int loop_length(Node* head){
      if(head == nullptr) return 0;
      Node* fast = head;
      Node* slow = head;
      while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return find_length(slow, fast);
      }
      return 0;
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

      std::cout << loop_length(head) << std::endl;

      free_List(head);

      return 0;
}