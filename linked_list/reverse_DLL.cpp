#include "doubly_structure.hpp"

Node* revDLL(Node* head){
      Node* current = head;
      Node* last = nullptr;
      while(current != nullptr){
            last = current -> back;
            current -> back = current -> next;
            current -> next = last;
            current = current -> back;
      }
      return last -> back;
}

// Node* revDLL(Node* head){
//       Node* current = head;
//       while(current != nullptr){
//             Node* temp = current -> next;
//             current -> next = current -> back;
//             current -> back = temp;
//             if(current -> back != nullptr){
//                   current = current -> back;
//             }
//             else{
//                   break;
//             }
//       }
//       return current;
// }

int main(){
      std::vector<int> vect = {1, 2, 3, 4, 5, 6};

      Node* head = convertArr2DLL(vect);

      print_DLL(head);

      head = revDLL(head);

      print_DLL(head);

      free_DLL(head);

      return 0;
}