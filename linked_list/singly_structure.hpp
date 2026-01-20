#ifndef SINGLY_STRUCTURE_HPP
#define SINGLY_STRUCTURE_HPP

#include <iostream>
#include <vector>

class Node{
      public:
            int data;
            Node* next;

            Node(int data1, Node* next1){
                  data = data1;
                  next = next1;
            }

            Node(int data1){
                  data = data1;
                  next = nullptr;
            }

            ~Node(){}
};

// Function: Convert an array into a linked list
// Returns the head pointer of the newly created linked list
Node* convertArr2LL(std::vector<int> &arr) {
      if (arr.empty()) return nullptr;   // handle empty array

      // First node becomes head
      Node* head = new Node(arr[0]);
      Node* mover = head;

      // Start from index 1 because index 0 is already used for head
      for (int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);   // create new node
            mover->next = temp;              // link previous node to new node
            mover = temp;                    // move forward
      }
      return head;
}

// Function: Count number of nodes in the linked list
int countNodes(Node* head) {
      int count = 0;
      Node* temp = head;

      // Traverse till the end
      while (temp != nullptr) {
            count++;
            temp = temp->next;
      }
      return count;
}

int search_element(Node* head, int num){
      int flag = 0;
      Node* temp = head;
      while(temp != nullptr){
            if(temp -> data == num){
                  flag = 1;
            }
            temp = temp -> next;
      }
      return flag;
}

// fucntion to cleanup
void free_List(Node* head) {
      while (head != nullptr) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
      }
}

void print_list(Node* head){
      Node* temp = head;
      while(temp != nullptr){
            std::cout << temp -> data << "\t";
            temp = temp -> next;
      }
      std::cout << "\n";
}

#endif
