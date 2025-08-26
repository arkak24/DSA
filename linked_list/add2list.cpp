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

            Node(int value, Node* next){
                  data = value;
                  next_addr = next;
            }
};

Node* convertArr2LL(std::vector<int> &arr){
      Node* head = new Node(arr[0]);
      Node* mover = head;
      for(int i = 1; i < arr.size(); i++){
            Node* temp = new Node(arr[i]);
            mover -> next_addr = temp;
            mover = temp;
      }
      return head;
}     

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
            }
            if(temp2 != nullptr){
                  sum = sum + temp2 -> data;
            }
            Node* newNode = new Node(sum % 10);
            carry = sum / 10;

            current -> next_addr = newNode;
            current = current -> next_addr;

            if(temp1 != nullptr){
                  temp1 = temp1 -> next_addr;
            }
            if(temp2 != nullptr){
                  temp2 = temp2 -> next_addr;
            }
      }
      if(carry != 0){
            Node* newNode = new Node(carry);
            current -> next_addr = newNode;
      }
      return dummy_head -> next_addr;
}

void print_list(Node* head){
      Node* temp = head;
      while(temp != nullptr){
            std::cout << temp -> data << "\t";
            temp = temp -> next_addr;
      }
      std::cout << "\n";
}

void free_DLL(Node* head){
      Node* temp = nullptr;
      while(head != nullptr){
            temp = head -> next_addr;
            delete head;
            head = temp;
      }
}

int main(){
      std::vector<int> vec1 = {1, 2, 3, 4, 5};
      std::vector<int> vec2 = {9, 8, 7, 6, 5};

      Node* head1 = convertArr2LL(vec1);
      Node* head2 = convertArr2LL(vec2);

      Node* head_of_sum = add_two_list(head1, head2);

      print_list(head_of_sum);

      free_DLL(head1);
      free_DLL(head2);
      free_DLL(head_of_sum);
      
      return 0;
}