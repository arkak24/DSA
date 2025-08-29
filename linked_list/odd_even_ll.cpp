#include "singly_structure.hpp"

// BRUTE
// TC : O(2n); SC : O(n)
// Node* odd_even_clubbed(Node* head){
//       if(head == nullptr || head -> next == nullptr) return head;
//       std::vector<int> vect;
//       Node* temp = head;
//       while(temp != nullptr && temp -> next != nullptr){
//             // if the number of nodes is odd then the (temp -> next != nullptr) will make the loop stop
//             // if the number of nodes is even then the (temp != nullptr) will make the loop stop
//             vect.push_back(temp -> data);
//             temp = temp -> next -> next;
//       }
//       // there might be nodes leftover so we must check because there are 2 conditions in the previous loop
//       if(temp != nullptr){
//             vect.push_back(temp -> data);
//       }

//       temp = head -> next;
//       while(temp != nullptr && temp -> next != nullptr){
//             vect.push_back(temp -> data);
//             temp = temp -> next -> next;
//       }
//       if(temp != nullptr){
//             vect.push_back(temp -> data);
//       }

//       temp = head;
//       int idx = 0;
//       while(temp != nullptr){
//             temp -> data = vect[idx];
//             idx++;
//             temp = temp -> next;
//       }
//       return head;
// }

// BETTER
// TC : O(n); SC : O(1)
Node* odd_even_clubbed(Node* head){
      if(head == nullptr || head -> next == nullptr) return head;

      Node* odd = head;
      Node* even = head -> next;
      Node* even_head = head -> next;

      while(even != nullptr && even -> next != nullptr){
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;

            odd = odd -> next;
            even = even -> next;
      }
      odd -> next = even_head;
      return head;
}

int main(){
      std::vector<int> vec = {1, 3, 4, 2, 5, 6, 7};

      Node* head = convertArr2LL(vec);

      head = odd_even_clubbed(head);

      print_list(head);

      free_List(head);
      
      return 0;
}