#ifndef DOUBLY_STRUCTURE
#define DOUBLY_STRUCTURE

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
      if(arr.empty()) return nullptr;

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

#endif