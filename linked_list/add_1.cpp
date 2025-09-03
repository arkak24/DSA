#include "singly_structure.hpp"

Node* reverse_LL(Node* head){
      if(head == nullptr || head -> next == nullptr){
            return head;
      }
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

Node* add_one(Node* head){
      head = reverse_LL(head);
      Node* temp = head;
      int carry = 1;
      while(temp != nullptr){
            temp -> data = temp -> data + carry;
            if(temp -> data < 10){
                  carry = 0;
                  break;
            }
            else{
                  temp -> data = 0;
                  carry = 1;
            }
            temp = temp -> next;
      }
      if(carry == 1){
            Node* new_head = new Node(1);
            head = reverse_LL(head);
            new_head -> next = head;
            return new_head;
      }
      head = reverse_LL(head);
      return head;
}

int main(){
      std::vector<int> vect = {1, 2, 3, 9, 9};
      Node* head = convertArr2LL(vect);
      head = add_one(head);
      print_list(head);
      free_List(head);

      return 0;
}