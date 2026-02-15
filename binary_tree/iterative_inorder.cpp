#include "lc_tree.hpp"

class Solution{
      public:
            vector<int> inorderTraversal(TreeNode* root){
                  vector<int> ans;
                  if(root == nullptr) return ans;

                  stack<TreeNode*> st;
                  TreeNode* curr = root;
                  while(!st.empty() || curr){
                        while(curr != nullptr){
                              st.push(curr);
                              curr = curr -> left;
                        }
                        curr = st.top();
                        st.pop();
                        ans.push_back(curr -> val);
                        curr = curr -> right;
                  }
                  return ans;
            }
};
