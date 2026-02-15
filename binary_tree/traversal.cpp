#include "make_tree.hpp"

void print_tree_inorder(node* node){
      if(node == nullptr) return;
      print_tree_inorder(node -> left);
      printf("%d\t", node -> data);
      print_tree_inorder(node -> right);
}

void print_tree_preorder(node* node){
      if(node == nullptr) return;
      printf("%d\t", node -> data);
      print_tree_preorder(node -> left);
      print_tree_preorder(node -> right);
}

void print_tree_postorder(node* node){
      if(node == nullptr) return;
      print_tree_postorder(node -> left);
      print_tree_postorder(node -> right);
      printf("%d\t", node -> data);
}

void print_tree(node* root){
      int choice;

      while(true){
            printf("\n\n1. Print the tree inorder\n");
            printf("2. Print the tree preorder\n");
            printf("3. Print the tree postorder\n");
            printf("4. Done\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if(choice == 1) print_tree_inorder(root);
            else if(choice == 2) print_tree_preorder(root);
            else if(choice == 3) print_tree_postorder(root);
            else if(choice == 4) return;
            else printf("Invalid input !\n");
      }
}

int main(){
      node* tree_root = make_tree();

      print_tree(tree_root);

      printf("\n");

      return 0;
}
