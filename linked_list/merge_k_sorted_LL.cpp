#include "singly_structure.hpp"

#include <queue>
#include <utility>
#include <algorithm>

// BRUTE
// TC : O(n*k + mlogm + m); SC : O(2m)
// Node* merge_k_lists(std::vector<Node*> &list_array){
//       std::vector<int> arr;
//       for(int i = 0; i < list_array.size(); i++){
//             Node* temp = list_array[i];
//             while(temp != nullptr){
//                   arr.push_back(temp -> data);
//                   temp = temp -> next;
//             }
//       }
//       std::sort(arr.begin(), arr.end());
//       Node* head = convertArr2LL(arr);
//       return head;
// }

// BETTER
// TC : O(~n^3); SC : O(1)
// Node* merge(Node* head1, Node* head2){
//       Node* t1 = head1;
//       Node* t2 = head2;
//       Node* dummy_node = new Node(-1);
//       Node* temp = dummy_node;
//       while(t1 != nullptr && t2 != nullptr){
//             if(t1 -> data < t2 -> data){
//                   temp -> next = t1;
//                   temp = t1;
//                   t1 = t1 -> next;
//             }
//             else{
//                   temp -> next = t2;
//                   temp = t2;
//                   t2 = t2 -> next;
//             }
//       }
//       if(t1 != nullptr){
//             temp -> next = t1;
//       }
//       else{
//             temp -> next = t2;
//       }
//       return dummy_node -> next;
// }
// Node* merge_k_lists(std::vector<Node*> &list_array){
//       Node* head = list_array[0];
//       for(int i = 1; i < list_array.size(); i++){
//             head = merge(head, list_array[i]);
//       }
//       return head;
// }

// OPTIMAL
// using a mini-heap
// TC : O(n*k) + O(n*k*3(logk)); SC : O(k)
Node* merge_k_lists(std::vector<Node*> &list_array){
      std::priority_queue<
            std::pair<int, Node*>, 
            std::vector<std::pair<int, Node*>>, 
            std::greater<std::pair<int, Node*>>
      > pq;

      for(int i = 0; i < list_array.size(); i++){ // k
            if(list_array[i] != nullptr){
                  pq.push({list_array[i] -> data, list_array[i]}); //logk
            }
      }
      Node* dummy_node = new Node(-1);
      Node* temp = dummy_node;
      while(!pq.empty()){ // k*n
            auto it = pq.top();     // top, pop, push takes logk
            pq.pop();
            if(it.second -> next){
                  pq.push({it.second -> next -> data, it.second -> next});
            }
            temp -> next = it.second;
            temp = temp -> next;
      }
      return dummy_node -> next;
}

int main(){
      std::vector<int> vec1 = {2, 4, 6};
      std::vector<int> vec2 = {1, 5, 6};
      std::vector<int> vec3 = {1, 1, 3, 5, 7};

      Node* head1 = convertArr2LL(vec1);
      Node* head2 = convertArr2LL(vec2);
      Node* head3 = convertArr2LL(vec3);

      std::vector<Node*> lists = {head1, head2, head3};

      Node* final_head = merge_k_lists(lists);
      print_list(final_head);
      free_List(final_head);

      return 0;
}