#include "singly_structure.hpp"

// TC : O(2n); SC : O(1)
Node* rotate_k_places(Node* head, int k){
      int len = 1;
      Node* temp = head;
      while(temp -> next != nullptr){
            len++;
            temp = temp -> next;
      }
      if(k % len == 0) return head;
      temp -> next = head;

      k = k % len;
      int num = len - k - 1;
      temp = head;
      while(num > 0){
            num--;
            temp = temp -> next;
      }
      head = temp -> next;
      temp -> next = nullptr;
      return head;
}

int main(){
      std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
      Node* head = convertArr2LL(vec);

      print_list(head);
      head = rotate_k_places(head, 4);
      print_list(head);

      free_List(head);
      return 0;
}