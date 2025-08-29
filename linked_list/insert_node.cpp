#include "singly_structure.hpp"

// Node* insert_head(Node* head){
//       int val;
//       std::cout << "Enter the value of the node : ";
//       std::cin >> val;
//       Node* temp = new Node(val);
//       temp -> next = head;
//       head = temp;
//       return head;
// }

// Node* insert_head(Node* head, int val){
//       return new Node(val, head);
// }

// Node* insert_tail(Node* head, int val){
//       if(head == nullptr){
//             return new Node(val); 
//       }
//       Node* temp = head;
//       while(temp -> next != nullptr){
//             temp = temp -> next;
//       }
//       Node* new_node = new Node(val);
//       temp -> next = new_node;
//       return head;
// }

// inserting according to given position
// Node* insert_kth(Node* head, int val, int k){
//       if(head == nullptr){
//             if(k == 1){
//                   return new Node(val);
//             }
//             else{
//                   return nullptr;
//             }
//       }
//       if(k == 1){
//             Node* temp = new Node(val, head);
//             return temp;
//       }
//       int count = 0;
//       Node* temp = head;
//       while(temp != nullptr){
//             count++;
//             if(count == k-1){
//                   Node* new_mem = new Node(val);
//                   new_mem -> next = temp -> next;
//                   temp -> next = new_mem;
//             }
//             temp = temp -> next;
//       }
//       return head;
// }

// inserting according to a given node present in the list
// inserting the node just before mentioned node
Node* insert_before_val(Node* head, int new_val, int element){
      if(head == nullptr){
            return nullptr;
      }
      if(head -> data == element){
            return new Node(new_val, head);
      }
      Node* temp = head;
      bool found = false;
      while(temp -> next != nullptr){
            if(temp -> next -> data == element){
                  Node* new_mem = new Node(new_val);
                  new_mem -> next = temp -> next;
                  temp -> next = new_mem;
                  found = true;
                  break;
            }
            temp = temp -> next;
      }
      if(found == false){
            // do nothing
      }
      return head;
}

int main(){
      std::vector<int> vect = {2, 3, 4, 5, 6};
      Node* head = convertArr2LL(vect);

      // head = insert_head(head);
      // head = insert_head(head, 10);
      // head = insert_tail(head, 10);
      // head = insert_kth(head, 10, 1);
      head = insert_before_val(head, 10, 3);

      Node* temp = head;
      while(temp != nullptr){
            std::cout << temp -> data << "\t";
            temp = temp -> next;
      }
      std::cout << "\n";

      return 0;
}