#include "lc_tree.hpp"

class Solution {
      public:
            // basically standing at each node ask that node
            // how many subtree in its left v/s in its right
            // tc: O(n); sc: O(n) -> in case of skew tree
            int maxDepth_1(TreeNode* root){
                  if(root == nullptr) return 0;

                  int lh = maxDepth_1(root -> left);
                  int rh = maxDepth_1(root -> right);

                  return (1 + max(lh, rh));
            }

            // similar to level order traversal approach
            // tc: O(n); sc: O(n)
            int maxDepth_2(TreeNode* root) {
                  if(root == nullptr) return 0;

                  queue<TreeNode*> qe;
                  qe.push(root);

                  int depth = 0;
                  while(!qe.empty()){
                        int sz = qe.size();
                        depth++;

                        for(int i = 0; i < sz; i++){
                              TreeNode* nd = qe.front();
                              qe.pop();

                              if(nd -> left != nullptr) qe.push(nd -> left);       
                              if(nd -> right != nullptr) qe.push(nd -> right);
                        }
                  }
                  return depth;
            }
};
