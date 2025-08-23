#include <iostream>
#include <vector>

class Node {
      public:
            int data;     // data stored in the node
            Node* next;   // pointer to the next node

            // Constructor 1: Initialize both data and next explicitly
            Node(int data1, Node* next1) {
                  data = data1;
                  next = next1;
            }

            // Constructor 2: Initialize data, automatically set next to nullptr
            Node(int data1) {
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
void freeList(Node* head) {
      while (head != nullptr) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
      }
}


int main() {
      std::vector<int> vect = {2, 3, 8, 5};       // input array

      // Convert array to linked list
      Node* head = convertArr2LL(vect);

      // Traversal: print each node's data
      Node* temp = head;
      std::cout << "Linked list elements: ";
      while (temp != nullptr) {                   // stop when temp hits null
            std::cout << temp->data << "\t";
            temp = temp->next;                      // move to next node
      }
      std::cout << "\n";

      // Count nodes
      int totalNodes = countNodes(head);
      std::cout << "Number of nodes: " << totalNodes << "\n";

      return 0;
}
