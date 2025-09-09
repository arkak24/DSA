#include "singly_structure.hpp"

// BRUTE
// store everyting into array -> sort -> put them into linked list

// BETTER
// TC : O(); SC : O()
Node* find_middle(Node* head){
      Node* slow = head;
      Node* fast = head -> next;
      while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
      }
      return slow;
}
Node* merge2LL(Node* list1, Node* list2){
      Node* dummy_node = new Node(-1);
      Node* temp = dummy_node;
      while(list1 != nullptr && list2 != nullptr){
            if(list1 -> data < list2 -> data){
                  temp -> next = list1;
                  temp = list1;
                  list1 = list1 -> next;
            }
            else{
                  temp -> next = list2;
                  temp = list2;
                  list2 = list2 -> next;
            }
      }
      if(list1 != nullptr) temp -> next = list1;
      else temp -> next = list2;
      return dummy_node -> next;
}
Node* merge_sort(Node* head){
      if(head == nullptr || head -> next == nullptr) return head;
      Node* middle = find_middle(head);
      Node* right = middle -> next;
      middle -> next = nullptr;
      Node* left = head;

      left = merge_sort(left);
      right = merge_sort(right);

      return merge2LL(left, right);
}

int main(){
      std::vector<int> vec = {4, 2, 1, 6, 7, 3};
      Node* head = convertArr2LL(vec);

      print_list(head);

      head = merge_sort(head);

      print_list(head);

      free_List(head);

      return 0;
}