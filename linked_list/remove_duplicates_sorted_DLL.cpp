#include "doubly_structure.hpp"

// TC : O(n); SC : O(1)
Node* remove_duplicates(Node* head){
      Node* temp = head;
      while(temp != nullptr && temp -> next != nullptr){
            Node* next_node = temp -> next;
            while(next_node != nullptr && (next_node -> data == temp -> data)){
                  Node* duplicate = next_node;
                  next_node = next_node -> next;
                  free(duplicate);
            }
            temp -> next = next_node;
            if(next_node != nullptr){
                  next_node -> prev = temp;
            }
            temp = temp -> next;
      }
      return head;
}

int main(){
      std::vector<int> vec = {1, 1, 2, 2, 3, 4};
      Node* head = convertArr2DLL(vec);
      print_DLL(head);

      head = remove_duplicates(head);
      print_DLL(head);
      free_DLL(head);

      return 0;
}