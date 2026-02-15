#include "lc_tree.hpp"

class Solution{
      public:
            // basic way
            vector<int> postorder_traversal_1(TreeNode* root){
                  stack<TreeNode*> st;
                  st.push(root);

                  vector<int> ans;

                  if(root == nullptr) return ans;

                  while(!st.empty()){
                        TreeNode* nd = st.top();
                        st.pop();
                        ans.push_back(nd -> val);

                        if(nd -> left != nullptr){
                              st.push(nd -> left);
                        }
                        if(nd -> right != nullptr){
                              st.push(nd -> right);
                        }
                  }
                  reverse(ans.begin(), ans.end());
                  return ans;
            }

            // 2 stack way
            vector<int> postorder_traversal_2(TreeNode* root){
                  vector<int> ans;
                  if(root == nullptr) return ans;

                  stack<TreeNode*> st1;
                  stack<TreeNode*> st2;
                  st1.push(root);
                  while(!st1.empty()){
                        TreeNode* nd = st1.top();
                        st1.pop();
                        st2.push(nd);

                        if(nd -> left != nullptr) st1.push(nd -> left);
                        if(nd -> right != nullptr) st1.push(nd -> right);
                  }
                  while(!st2.empty()){
                        ans.push_back(st2.top() -> val);
                        st2.pop();
                  }
                  return ans;
            }

            // 1 stack way
            vector<int> postorder_traversal_3(TreeNode* root){
                  
            }

            // Morris traversal
};
