#include "singly_structure.hpp"

// Node* delete_head(Node* head){
//       Node* temp = head;
//       head = head -> next;
//       delete temp;
//       return head;
// }

// Node* delete_tail(Node* head){
//       if(head == nullptr || head -> next == nullptr){
//             return nullptr; // as there is no tail present in this case
//       }
//       else{
//             Node* temp = head;
//             while(temp -> next -> next != nullptr){
//                   temp = temp -> next;
//             }
//             delete temp -> next;
//             temp -> next = nullptr;
//             return head;
//       }
// }

// deleting element by its position
// Node* delete_kth(Node* head, int k){
//       if(head == nullptr) return head;
//       if(k == 1){
//             Node* temp = head;
//             head = head -> next;
//             delete temp;
//             return head;
//       }
//       int count = 0;
//       Node* temp = head;
//       Node* prev = nullptr;
//       while(temp != nullptr){
//             count++;
//             if(count == k){
//                   prev -> next = prev -> next -> next;
//                   delete temp;
//                   break;
//             }
//             prev = temp;
//             temp = temp -> next;
//       }
//       return head;
// }

// deleting element by its value
Node* delete_node(Node* head, int val){
      if(head == nullptr) return head;
      if(head -> data == val){
            Node* temp = head;
            head = head -> next;
            delete temp;
            return head;
      }
      Node* temp = head -> next;
      Node* prev = head;
      while(temp != nullptr){
            if(temp -> data == val){
                  prev -> next = prev -> next -> next;
                  delete temp;
                  break;
            }
            prev = temp;
            temp = temp -> next;
      }
      return head; 
}

int main(){
      std::vector<int> vect = {2, 3, 4, 5, 6};
      Node* head = convertArr2LL(vect);

      // head = delete_head(head);
      // head = delete_tail(head);
      // head = delete_kth(head, 6);
      head = delete_node(head, 9);

      print_list(head);

      return 0;
}