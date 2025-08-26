#include <iostream>
#include <vector>

class Node{
      public:
            int data;
            Node* next;
            Node* back;

            Node(int data1){
                  data = data1;
                  next = nullptr;
                  back = nullptr;
            }

            Node(int data1, Node* next1, Node* back1){
                  data = data1;
                  next = next1;
                  back = back1;
            
      }
};

Node* convertArr2DLL(std::vector<int> &arr){
      Node* head = new Node(arr[0]);
      Node* prev = head;

      for(int i = 1; i < arr.size(); i++){
            Node* temp = new Node(arr[i], nullptr, prev);
            prev -> next = temp;
            prev = temp;
      }

      return head;
}

void print_DLL(Node* head){
      Node* temp = head;
      while(temp != nullptr){
            std::cout << temp -> data << "\t";
            temp = temp -> next;
      }
      std::cout << "\n";
}

void free_DLL(Node* head){
      Node* temp = nullptr;
      while(head != nullptr){
            temp = head -> next;
            delete head;
            head = temp;
      }
}

Node* revDLL(Node* head){
      Node* current = head;
      Node* last = nullptr;
      while(current != nullptr){
            last = current -> back;
            current -> back = current -> next;
            current -> next = last;
            current = current -> back;
      }
      return last -> back;
}

// Node* revDLL(Node* head){
//       Node* current = head;
//       while(current != nullptr){
//             Node* temp = current -> next;
//             current -> next = current -> back;
//             current -> back = temp;
//             if(current -> back != nullptr){
//                   current = current -> back;
//             }
//             else{
//                   break;
//             }
//       }
//       return current;
// }

int main(){
      std::vector<int> vect = {1, 2, 3, 4, 5, 6};

      Node* head = convertArr2DLL(vect);

      print_DLL(head);

      head = revDLL(head);

      print_DLL(head);

      free_DLL(head);

      return 0;
}