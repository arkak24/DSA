#include "singly_structure.hpp"

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

Node*  get_kth_node(Node* temp, int k){
      k = k - 1;
      while(temp != nullptr && k > 0){
            k--;
            temp = temp -> next;
      }
      return temp;
}

Node* k_reverse(Node* head, int k){
      Node* temp = head;
      Node* prev_last = nullptr;
      while(temp != nullptr){
            Node* k_th_node = get_kth_node(temp, k);
            if(k_th_node == nullptr){
                  if(prev_last != nullptr){
                        prev_last -> next = temp;
                  }
                  break;
            }
            Node* next_node = k_th_node -> next;
            k_th_node -> next = nullptr;
            rev_LL(temp);
            if(temp == head){
                  head = k_th_node;
            }
            else{
                  prev_last -> next = k_th_node;
            }
            prev_last = temp;
            temp = next_node;
      }
      return head;
}

int main(){
      std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
      Node* head = convertArr2LL(vec);

      print_list(head);
      head = k_reverse(head, 3);
      print_list(head);

      free_List(head);

      return 0;
}