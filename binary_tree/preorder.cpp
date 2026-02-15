#include "lc_tree.hpp"

class Solution {
      public:
            // RECURSIVE
            // this will use stack space
            // for large treees(deep treees) it will led to stack overflow
            void preorder(TreeNode* root, vector<int>& ans){
                  if(root == nullptr) return;

                  ans.push_back(root -> val);
                  preorder(root -> left, ans);
                  preorder(root -> right, ans);
            }
            vector<int> preorderTraversal(TreeNode* root) {
                  vector<int> ans;
                  preorder(root, ans);
                  return ans;
            }


            // ITERATIVE
            // this will not use the stack space
            // this uses stack to mimic the stack space used int he recursive process
            vector<int> preorder_traversal(TreeNode* root){
                  stack<TreeNode*> st;
                  st.push(root);

                  vector<int> ans;

                  if(root == nullptr) return ans;

                  while(!st.empty()){
                        TreeNode* nd = st.top();
                        st.pop();
                        ans.push_back(nd -> val);

                        if(nd -> right != nullptr){
                              st.push(nd -> right);
                        }
                        if(nd -> left != nullptr){
                              st.push(nd -> left);
                        }
                  }
                  return ans;
            }
};

// same approach for the inorder and the postorder traversal methods

/*

Don't do this:

class Solution {
      public:
            vector<int> ans;
            vector<int> preorderTraversal(TreeNode* root) {
                  ans.push_back(root -> val);
                  preorderTraversal(root -> left);
                  preorderTraversal(root -> right);
                  return ans;
            }
};

making the ans vector global works but is not good practice
when we call this function again we need to clear the ans vector manually
other wise it will create bug

besides global variables are bad in multithreaded programs
this is not good softwares

*/
