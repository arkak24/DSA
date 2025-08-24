#include <iostream>
#include <vector>

class Node{
      public:
            int data;
            Node* next_addr;

            Node(int value){
                  data = value;
                  next_addr = nullptr;
            }
};

Node* convertArr2LL(std::vector<int> arr){
      Node* head = new Node(arr[0]);
      Node* mover = head;
      for(int i = 1; i < arr.size(); i++){
            Node* temp = new Node(arr[i]);
            mover -> next_addr = temp;
            mover = temp;
      }
      return head;
}     

// Node* delete_head(Node* head){
//       Node* temp = head;
//       head = head -> next_addr;
//       delete temp;
//       return head;
// }

// Node* delete_tail(Node* head){
//       if(head == nullptr || head -> next_addr == nullptr){
//             return nullptr; // as there is no tail present in this case
//       }
//       else{
//             Node* temp = head;
//             while(temp -> next_addr -> next_addr != nullptr){
//                   temp = temp -> next_addr;
//             }
//             delete temp -> next_addr;
//             temp -> next_addr = nullptr;
//             return head;
//       }
// }

// deleting element by its position
// Node* delete_kth(Node* head, int k){
//       if(head == nullptr) return head;
//       if(k == 1){
//             Node* temp = head;
//             head = head -> next_addr;
//             delete temp;
//             return head;
//       }
//       int count = 0;
//       Node* temp = head;
//       Node* prev = nullptr;
//       while(temp != nullptr){
//             count++;
//             if(count == k){
//                   prev -> next_addr = prev -> next_addr -> next_addr;
//                   delete temp;
//                   break;
//             }
//             prev = temp;
//             temp = temp -> next_addr;
//       }
//       return head;
// }

// deleting element by its value
Node* delete_node(Node* head, int val){
      if(head == nullptr) return head;
      if(head -> data = val){
            Node* temp = head;
            head = head -> next_addr;
            delete temp;
            return head;
      }
      int count = 0;
      Node* temp = head;
      Node* prev = nullptr;
      while(temp != nullptr){
            count++;
            if(temp -> data = val){
                  prev -> next_addr = prev -> next_addr -> next_addr;
                  delete temp;
                  break;
            }
            prev = temp;
            temp = temp -> next_addr;
      }
      return head; 
}

int main(){
      std::vector<int> vect = {2, 3, 4, 5, 6};
      Node* head = convertArr2LL(vect);

      // head = delete_head(head);
      // head = delete_tail(head);
      // head = delete_kth(head, 3);

      Node* temp = head;
      while(temp != nullptr){
            std::cout << temp -> data << "\t";
            temp = temp -> next_addr;
      }
      std::cout << "\n";

      return 0;
}