// in this q the each node to the end of the child is sorted

#include <iostream>
#include <vector>
#include <algorithm>

class Node{
      public:
            int data;
            Node* next;
            Node* child;
            
            Node(int data1){
                  data = data1;
                  next = nullptr;
                  child = nullptr;
            }
};

Node* convert2LL_parent(std::vector<int> &arr){
      if(arr.size() == 0) return nullptr;
      Node* head = new Node (arr[0]);
      Node* temp = head;
      for(int i = 1; i < arr.size(); i++){
            Node* new_node = new Node(arr[i]);
            temp -> next = new_node;
            temp = temp -> next;
      }
      return head;
}

Node* convert2LL(std::vector<int> &arr){
      if(arr.size() == 0) return nullptr;
      Node* head = new Node (arr[0]);
      Node* temp = head;
      for(int i = 1; i < arr.size(); i++){
            Node* new_node = new Node(arr[i]);
            temp -> child = new_node;
            temp = temp -> child;
      }
      return head;
}

// BRUTE
// TC : O(x*logx + 2(n*m)), x = n+m; SC : O(2(n*m))
// Node* flatten_LL(Node* head){
//       std::vector<int> arr;
//       Node* temp1 = head;
//       while(temp1 != nullptr){
//             Node* temp2 = temp1;
//             while(temp2 != nullptr){
//                   arr.push_back(temp2 -> data);
//                   temp2 = temp2 -> child;
//             }
//             temp1 = temp1 -> next;
//       }
//       std::sort(arr.begin(), arr.end());
//       head = convert2LL(arr);
//       return head;
// }

// BETTER
// recursive approach
// TC : n*O(2m); SC : O(n), recursive stack space
Node* merge(Node* list1, Node* list2){
      Node* dummy_node = new Node(-1);
      Node* result = dummy_node;
      while(list1 != nullptr && list2 != nullptr){
            if(list1 -> data < list2 -> data){
                  result -> child = list1;
                  result = list1;
                  list1 = list1 -> child;
            }
            else{
                  result -> child = list2;
                  result = list2;
                  list2 = list2 -> child;
            }
            result -> next = nullptr;
      }
      if(list1 != nullptr){
            result -> child = list1;
      }
      else{
            result -> child = list2;
      }
      if(dummy_node -> child) dummy_node -> child -> next = nullptr;
      return dummy_node -> child;
}
Node* flatten_LL(Node* head){
      if(head == nullptr || head -> next == nullptr) return head;
      Node* merged_head = flatten_LL(head -> next);
      head = merge(head, merged_head);
      return head;
}

int main(){
      std::vector<int> vec = {3, 2, 1, 4, 5};

      std::vector<std::vector<int>> child = {{}, {10}, {7, 11, 12}, {9}, {6, 8}};
      int i = 0;

      Node* head = convert2LL_parent(vec);
      Node* temp = head;
      while(temp != nullptr && i < child.size()){
            Node* temp_child = convert2LL(child[i]);
            temp -> child = temp_child;
            i++;
            temp = temp -> next;
      }

      Node* ans = flatten_LL(head);

      Node* temp_print = ans;
      while(temp_print != nullptr){
            std::cout << temp_print -> data << "\t";
            temp_print = temp_print -> child;
      }
      std::cout << "\n";

      return 0;
}