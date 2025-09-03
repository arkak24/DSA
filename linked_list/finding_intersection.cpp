#include "singly_structure.hpp"

#include <map>

// TC : O(n1logn1 + n2logn1); SC : O(n1)
// Node* intersection(Node* head1, Node* head2){
//       std::map<Node*, int> mpp;
//       Node* temp1 = head1;
//       while(temp1 != nullptr){
//             mpp[temp1] = 1;
//             temp1 = temp1 -> next;
//       }
//       Node* temp2 = head2;
//       while(temp2 != nullptr){
//             if(mpp.find(temp2) != mpp.end()){
//                   return temp2;
//             }
//             temp2 = temp2 -> next;
//       }
//       return nullptr;
// }

// TC : O(n1+2n2 n2>n1); SC : O(1)
// Node* finding_collision(Node* head1, Node* head2, int diff){      // (long, short, difference)
//       for(int i = 0; i < diff; i++){
//             head1 = head1 -> next;
//       }
//       while(head1 != head2){
//             head1 = head1 -> next;
//             head2 = head2 -> next;
//       }
//       return head1;
// }
// Node* intersection(Node* head1, Node* head2){
//       int n1 = 0;
//       Node* temp1 = head1;
//       while(temp1 != nullptr){
//             n1++;
//             temp1 = temp1 -> next;
//       }
//       int n2 = 0;
//       Node* temp2 = head2;
//       while(temp2 != nullptr){
//             n2++;
//             temp2 = temp2 -> next;
//       }
//       if(n1 > n2){
//             return finding_collision(head1, head2, n1-n2);  
//       }
//       else{
//             return finding_collision(head2, head1, n2-n1);
//       }
// }

// TC : O(n1+n2); SC : O(1) 
Node* intersection(Node* head1, Node* head2){
      Node* temp1 = head1;
      Node* temp2 = head2;
      while(temp1 != temp2){
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
            
            if(temp1 == temp2) return temp1;

            if(temp1 == nullptr) temp1 = head2;
            if(temp2 == nullptr) temp2 = head1;
      }
      return temp1;
}

int main(){
      std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7};
      std::vector<int> vec2 = {8, 9, 0};

      Node* head1 = convertArr2LL(vec1);
      Node* head2 = convertArr2LL(vec2);

      while(head2 != nullptr){
            head2 = head2 -> next;
      }
      head2 = head1 -> next -> next -> next;
      std::cout << "original: " << head1 -> next -> next -> next << std::endl;

      std::cout << "output: " << intersection(head1, head2) << std::endl;
      
      return 0;
}