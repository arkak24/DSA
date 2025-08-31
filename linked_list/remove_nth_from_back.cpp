#include "singly_structure.hpp"

// BRUTE
// TC : O(count) + O(count - num); SC : O(1)
// Node* remove_nth_from_back(Node* head, int num){
//       int count = 0;
//       Node* temp = head;
//       while(temp != nullptr){
//             count++;
//             temp = temp -> next;
//       }
//       if(count == num){
//             Node* newhead = head -> next;
//             delete head;
//             return newhead;
//       }
//       int result = count - num;
//       temp = head;
//       while(temp != nullptr){
//             result--;
//             if(result == 0){
//                   break;
//             }
//             temp = temp -> next;
//       }
//       Node* temp_node = temp -> next;
//       temp -> next = temp -> next -> next;
//       delete temp_node;
//       return head;
// }

// BETTER
// TC : O(length_LL); SC : O(1)
Node* remove_nth_from_back(Node* head, int num){
      Node* fast = head;
      Node* slow = head;
      Node* temp_node = nullptr;
      for(int i = 0; i < num; i++){
            fast = fast -> next;
      }
      if(fast == nullptr){
            temp_node = head;
            head = head -> next;
            delete temp_node;
            return head;
      }
      while(fast -> next != nullptr){
            fast = fast -> next;
            slow = slow -> next;
      }
      temp_node = slow -> next;
      slow -> next = slow -> next -> next;
      delete temp_node;
      return head;
}

int main(){
      std::vector<int> vect = {1, 2, 3, 4, 5, 6};     
      int num = 6;
      Node* head = convertArr2LL(vect);

      head = remove_nth_from_back(head, num);

      print_list(head);
      free_List(head);

      return 0;
}