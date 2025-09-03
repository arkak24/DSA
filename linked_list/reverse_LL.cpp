#include "singly_structure.hpp"
#include <stack>

// BRUTE
// TC : O(2n); SC : O(n)
// Node* rev_LL(Node* head){
//       std::stack<int> st;
//       Node* temp = head;
//       while(temp != nullptr){
//             st.push(temp -> data);
//             temp = temp -> next;
//       }
//       temp = head;
//       while(temp != nullptr){
//             temp -> data = st.top();
//             st.pop();
//             temp = temp -> next;
//       }
//       return head;
// }

// OPTIMAL
// TC : O(n); SC : O(1)
// Node* rev_LL(Node* head){
//       Node* back = nullptr;
//       Node* current = head;
//       Node* front = nullptr;

//       while(current != nullptr){
//             front = current -> next;
//             current -> next = back;
//             back = current;
//             current = front;
//       }

//       return back;
// }

Node* rev_LL(Node* head){
      
}

int main(){
      std::vector<int> vect = {1, 2, 3, 4, 5, 6};
      Node* head = convertArr2LL(vect);

      head = rev_LL(head);
      print_list(head);
      free_List(head);

      return 0;
}