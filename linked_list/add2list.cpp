#include "singly_structure.hpp"

Node* add_two_list(Node* head1, Node* head2){
      Node* dummy_head = new Node(-1);
      Node* current = dummy_head;
      Node* temp1 = head1;
      Node* temp2 = head2;

      int carry = 0;

      while(temp1 != nullptr || temp2 != nullptr){
            int sum = carry;
            if(temp1 != nullptr){
                  sum = sum + temp1 -> data;
                  temp1 = temp1 -> next;
            }
            if(temp2 != nullptr){
                  sum = sum + temp2 -> data;
                  temp2 = temp2 -> next;
            }
            Node* newNode = new Node(sum % 10);
            carry = sum / 10;

            current -> next = newNode;
            current = current -> next;
      }
      if(carry != 0){
            Node* newNode = new Node(carry);
            current -> next = newNode;
      }
      return dummy_head -> next;
}

int main(){
      std::vector<int> vec1 = {1, 2, 3, 4, 5};
      std::vector<int> vec2 = {9, 8, 7, 6, 5};

      Node* head1 = convertArr2LL(vec1);
      Node* head2 = convertArr2LL(vec2);

      Node* head_of_sum = add_two_list(head1, head2);

      print_list(head_of_sum);

      free_List(head2);
      free_List(head1);
      free_List(head_of_sum);
      
      return 0;
}