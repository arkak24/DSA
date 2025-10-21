#include <iostream>
#include <vector>
#include <queue>

#include "make_tree.hpp"

std::vector<std::vector<int>> level_order(node* root){
      std::vector<std::vector<int>> ans;
      if(root == nullptr) return ans;

      std::queue<node*> qe;
      qe.push(root);

      while(!qe.empty()){
            int size = qe.size();
            std::vector<int> level;
            for(int i = 0; i < size; i++){
                  node* nd = qe.front();
                  qe.pop();

                  if(nd -> left != nullptr){
                        qe.push(nd -> left);
                  }
                  if(nd -> right != nullptr){
                        qe.push(nd -> right);
                  }
                  level.push_back(nd -> data);
            }
            ans.push_back(level);
      }
      return ans;
}

int main(){
      node* root = sample_tree();

      std::vector<std::vector<int>> result = level_order(root);

      for(int i = 0; i < result.size(); i++){
            for(int j = 0; j < result[i].size(); j++){
                  std::cout << result[i][j] << "\t";
            }
      }
      std::cout << "\n";

      return 0;
}
