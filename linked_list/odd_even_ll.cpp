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

void print_list(Node* head){
      Node* temp = head;
      while(temp != nullptr){
            std::cout << temp -> data << "\t";
            temp = temp -> next_addr;
      }
      std::cout << "\n";
}

void free_LL(Node* head){
      Node* temp = nullptr;
      while(head != nullptr){
            temp = head -> next_addr;
            delete head;
            head = temp;
      }
}

// BRUTE
// TC : O(2n); SC : O(n)
// Node* odd_even_clubbed(Node* head){
//       if(head == nullptr || head -> next_addr == nullptr) return head;
//       std::vector<int> vect;
//       Node* temp = head;
//       while(temp != nullptr && temp -> next_addr != nullptr){
//             // if the number of nodes is odd then the (temp -> next_addr != nullptr) will make the loop stop
//             // if the number of nodes is even then the (temp != nullptr) will make the loop stop
//             vect.push_back(temp -> data);
//             temp = temp -> next_addr -> next_addr;
//       }
//       // there might be nodes leftover so we must check because there are 2 conditions in the previous loop
//       if(temp != nullptr){
//             vect.push_back(temp -> data);
//       }

//       temp = head -> next_addr;
//       while(temp != nullptr && temp -> next_addr != nullptr){
//             vect.push_back(temp -> data);
//             temp = temp -> next_addr -> next_addr;
//       }
//       if(temp != nullptr){
//             vect.push_back(temp -> data);
//       }

//       temp = head;
//       int idx = 0;
//       while(temp != nullptr){
//             temp -> data = vect[idx];
//             idx++;
//             temp = temp -> next_addr;
//       }
//       return head;
// }

Node* odd_even_clubbed(Node* head){
      if(head == nullptr || head -> next_addr == nullptr) return head;

      Node* odd = head;
      Node* even = head -> next_addr;
      Node* even_head = head -> next_addr;

      while(even != nullptr && even -> next_addr != nullptr){
            odd -> next_addr = odd -> next_addr -> next_addr;
            even -> next_addr = even -> next_addr -> next_addr;

            odd = odd -> next_addr;
            even = even -> next_addr;
      }
      odd -> next_addr = even_head;
      return head;
}

int main(){
      std::vector<int> vec = {1, 3, 4, 2, 5, 6, 7};

      Node* head = convertArr2LL(vec);

      head = odd_even_clubbed(head);

      print_list(head);

      free_LL(head);
      
      return 0;
}