#include "singly_structure.hpp"

// TC : O(n1+n2); SC : O(1)
Node* merge(Node* head1, Node* head2){
      Node* t1 = head1;
      Node* t2 = head2;
      Node* dummy_node = new Node(-1);
      Node* temp = dummy_node;
      while(t1 != nullptr && t2 != nullptr){
            if(t1 -> data < t2 -> data){
                  temp -> next = t1;
                  temp = t1;
                  t1 = t1 -> next;
            }
            else{
                  temp -> next = t2;
                  temp = t2;
                  t2 = t2 -> next;
            }
      }
      if(t1 != nullptr){
            temp -> next = t1;
      }
      else{
            temp -> next = t2;
      }
      return dummy_node -> next;
}

int main(){
      std::vector<int> vec1 = {1, 3, 3, 5, 7, 9};
      std::vector<int> vec2 = {2, 4, 6, 6, 8};

      Node* head1 = convertArr2LL(vec1);
      Node* head2 = convertArr2LL(vec2);

      Node* head = merge(head1, head2);
      print_list(head);

      free_List(head);

      return 0;
}