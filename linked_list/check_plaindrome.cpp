#include "singly_structure.hpp"

#include <stack>

// BRUTE
// using a stack
// TC : O(2n); SC : O(n)
// bool check_plaindrome(Node* head){
//       std::stack<int> st;
//       Node* temp = head;
//       while(temp != nullptr){
//             st.push(temp -> data);
//             temp = temp -> next;
//       }
//       temp = head;
//       while(temp != nullptr){
//             if(temp -> data != st.top()){
//                   return false;
//             }
//             st.pop();
//             temp = temp -> next;
//       }
//       return true;
// }

// BETTER
// two pointer approach
// TC : O(2n); SC : O(1)
Node* rev_LL(Node* head){
      Node* back = nullptr;
      Node* current = head;
      Node* front = nullptr;

      while(current != nullptr){
            front = current -> next;
            current -> next = back;
            back = current;
            current = front;
      }

      return back;
}
bool check_plaindrome(Node* head){
      Node* fast = head -> next;
      Node* slow = head;

      while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
      }

      Node* new_head = rev_LL(slow -> next);

      Node* first = head;
      Node* second = new_head;

      while(second != nullptr){
            if(first -> data != second -> data){
                  rev_LL(new_head);
                  return false;
            }
            first = first -> next;
            second = second -> next;
      }
      rev_LL(new_head);
      return true;
}

int main(){
      std::vector<int> vect = {1, 2, 3, 3, 2, 1, 8};
      Node* head = convertArr2LL(vect);

      bool result = check_plaindrome(head);
      std::cout << result << std::endl;
      return 0;
}