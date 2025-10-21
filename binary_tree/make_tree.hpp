// binary tree program 

#ifndef MAKE_TREE_HPP
#define MAKE_TREE_HPP

#include<iostream>
#include<cstdio>
#include<cstdlib>

typedef struct node{
      int data;
      struct node* left;
      struct node* right;
      struct node* parent;
}node;

inline node* root = nullptr;
inline node* new_node = nullptr;
inline node* temp = nullptr;
inline node* for_storing_parent_address = nullptr;
inline node* ptr = nullptr;

inline void insert_new_node(){
      int branch_choice;
      printf("\n      |\n      |\n      |\n");
      printf("      ------- 1. Add branch to left\n");
      printf("              2. Add branch to right\n");
      printf("                 Enter your choice : ");
      scanf("%d", &branch_choice);

      if(branch_choice == 1){
            if(temp -> left != nullptr){
                  printf("                 Left position already occupied\n");
                  // printf("Left position already occupied\n");
                  // char update_choice;
                  // printf("Do you want to update the value? (Y/N) : \n");
                  // scanf("%c", &update_choice);
                  // if(update_choice == 'Y' || update_choice == 'y'){
                  //       // code to update the value
                  // }
            }
            else{
                  int value;
                  printf("                 Enter the value to insert : ");
                  scanf("%d", &value);

                  new_node = (node*)malloc(sizeof(node));
                  new_node -> data = value;
                  new_node -> left = nullptr;
                  new_node -> right = nullptr;
                  new_node -> parent = nullptr;

                  for_storing_parent_address = temp;
                  temp -> left = new_node;
                  temp = new_node;
                  temp -> parent = for_storing_parent_address;
            }
      }
      else if(branch_choice == 2){
            if(temp -> right != nullptr){
                  printf("                 Right position already occupied\n");
            }
            else{
                  int value;
                  printf("                 Enter the value to insert : ");
                  scanf("%d", &value);

                  new_node = (node*)malloc(sizeof(node));
                  new_node -> data = value;
                  new_node -> left = nullptr;
                  new_node -> right = nullptr;
                  new_node -> parent = nullptr;

                  for_storing_parent_address = temp;
                  temp -> right = new_node;
                  temp = new_node;
                  temp -> parent = for_storing_parent_address;
            }
      }
      else{
            printf("                 Invalid input\n");
      }
}

inline void back_to_parent(){
      if(temp != root){
            temp = temp -> parent;
      }
}

inline node* make_tree(){
      // taking input of the root seperately
      int root_data;
      printf("Enter the root data : ");
      scanf("%d", &root_data);

      new_node = (node*)malloc(sizeof(node));

      new_node -> data = root_data;
      new_node -> left = nullptr;
      new_node -> right = nullptr;
      new_node -> parent = nullptr;

      root = new_node; // this stays fized throughout the program
      temp = new_node;

      // taking input of the branches
      int choice;
      while(1){
            printf("\n\n1.Insert new branch\n");
            printf("2.Go back to the parent\n");
            printf("3.Done\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);

            switch(choice){
                  case 1 : insert_new_node();
                  break;

                  case 2 : back_to_parent();
                  break;

                  case 3 : // free the memory
                  printf("\n");
                  return root;
                  break;

                  default : printf("Invalid input\n");
            }
      }
}

inline node* sample_tree() {

      //         10
      //        /  \
      //       5    20
      //      / \   / \
      //     3  7  15  30

      node* n10 = (node*)malloc(sizeof(node));
      node* n5  = (node*)malloc(sizeof(node));
      node* n20 = (node*)malloc(sizeof(node));
      node* n3  = (node*)malloc(sizeof(node));
      node* n7  = (node*)malloc(sizeof(node));
      node* n15 = (node*)malloc(sizeof(node));
      node* n30 = (node*)malloc(sizeof(node));

      n10->data = 10;
      n5->data  = 5;
      n20->data = 20;
      n3->data  = 3;
      n7->data  = 7;
      n15->data = 15;
      n30->data = 30;

      n10->left = n5;   n10->right = n20;  n10->parent = nullptr;
      n5->left = n3;    n5->right = n7;    n5->parent = n10;
      n20->left = n15;  n20->right = n30;  n20->parent = n10;
      n3->left = n3->right = nullptr;      n3->parent = n5;
      n7->left = n7->right = nullptr;      n7->parent = n5;
      n15->left = n15->right = nullptr;    n15->parent = n20;
      n30->left = n30->right = nullptr;    n30->parent = n20;

      root = n10;
      temp = n10;

      std::cout << R"(
                  10
                 /  \
                5    20
               / \   / \
              3  7  15  30
      )";
      std::cout << "\n";

      return root;
}

inline void free_tree(node*& root){
      if(root == nullptr) return;
      
      free_tree(root -> left);
      free_tree(root -> right);

      free(root);
      root = nullptr;
}

#endif
