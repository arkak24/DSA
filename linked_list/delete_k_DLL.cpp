#include "doubly_structure.hpp"

// TC : O(n); SC : O(1)
Node* delete_occurences(Node* head, int k){
      Node* temp = head;
      while(temp != nullptr){
            if(temp -> data == k){
                  if(temp == head){
                        head = temp -> next;
                  }
                  Node* next_node = temp -> next;
                  Node* prev_node = temp -> prev;
                  if(next_node != nullptr){
                        next_node -> prev = prev_node;
                  }
                  if(prev_node != nullptr){
                        prev_node -> next = next_node;
                  }
                  free(temp);
                  temp = next_node;
            }
            else{
                  temp = temp -> next;
            }
      }
      return head;
}

int main(){
      std::vector<int> vec = {1, 1, 2, 3, 1, 4, 1, 5, 1, 1};
      Node* head = convertArr2DLL(vec);
      print_DLL(head);

      head = delete_occurences(head, 1);
      print_DLL(head);
      free_DLL(head);

      return 0;
}